/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:32:38 by tofujiwa          #+#    #+#             */
/*   Updated: 2023/09/15 18:51:17 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q so_long");
// }

void	print_error(int num)
{
	if (num == ARG_ERROR)
		ft_printf ("Error\narg_is_invalid\n");
	else if (num == OPEN_ERROR)
		ft_printf ("Error\nopen_error\n");
	else if (num == MALLOC_ERROR)
		ft_printf ("Error\nmalloc_error\n");
	else if (num == MAP_ERROR)
		ft_printf ("Error\nmap_error\n");
	exit (1);
}

int	destroy_window_hook(t_data *data_ptr)
{
	close_game(data_ptr, FALSE);
	return (1);
}

int	key_hook(int key, t_data *data_ptr)
{
	int		success;
	t_move	prev_post;

	success = 0;
	prev_post.p_y = data_ptr->img.player.move.p_y;
	prev_post.p_x = data_ptr->img.player.move.p_x;
	if (key == KEY_A)
		success = move(&(data_ptr->map), &(data_ptr->img.player), LEFT);
	else if (key == KEY_D)
		success = move(&(data_ptr->map), &(data_ptr->img.player), RIGHT);
	else if (key == KEY_W)
		success = move(&(data_ptr->map), &(data_ptr->img.player), UP);
	else if (key == KEY_S)
		success = move(&(data_ptr->map), &(data_ptr->img.player), DOWN);
	else if (key == KEY_ESC)
		close_game(data_ptr, TRUE);
	else
		return (0);
	if (success == 1)
		clear_game(data_ptr);
	render_img(data_ptr, data_ptr->img.player.move.p_y, \
	data_ptr->img.player.move.p_x);
	render_img(data_ptr, prev_post.p_y, prev_post.p_x);
	return (0);
}

int	move(t_map *map, t_player *player, int flag)
{
	char	next_val;

	next_val = get_next_val(*map, player->move, flag);
	if (next_val == '1')
		return (0);
	else if (next_val == '0')
		move_to_tile(map, player, flag);
	else if (next_val == 'C')
		move_to_collect(map, player, flag);
	else if (next_val == 'E' && map->collect_c != map->count_c)
		move_to_exit(map, player, flag);
	else if (next_val == 'E' && map->collect_c == map->count_c)
		return (1);
	printf("%d\n", ++(player->move_count));
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_move	move;
	t_data	data;
	char	**map_data;

	if (argc != 2)
		print_error (ARG_ERROR);
	fd = open (argv[1], O_RDONLY);
	if (fd < 0)
		print_error (OPEN_ERROR);
	init_relate_map (&(data.map), &move);
	data.map.str = read_map (argv, fd, &(data.map));
	map_data = copy_map (&(data.map));
	check_map (argv, &(data.map));
	check_path (map_data, &(data.map), &move);
	init_relate_play (&data);
	render_map (&data);
	mlx_hook (data.window, 02, 1L << 0, key_hook, &data);
	mlx_hook (data.window, 17, 1L << 17, destroy_window_hook, &data);
	mlx_loop (data.mlx);
	free_double_point (data.map.str, map_data);
	return (0);
}
