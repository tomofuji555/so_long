/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:32:38 by tofujiwa          #+#    #+#             */
/*   Updated: 2023/09/11 18:55:35 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(int num)
{
	if (num == ARG_ERROR)
		ft_printf ("Error\narg_is_invalid\n");
	else if (num == OPEN_ERROR)
		ft_printf ("Error\nopen_error\n");
	else if (num == MALLOC_ERROR)
		ft_printf ("Error\nmalloc_error\n");
	else if (num == NOT_RECTANGLE)
		ft_printf ("Error\nis_not_rectangle\n");
	else if (num == ELEMENTS_ERROR)
		ft_printf ("Error\nelements_is_wrong\n");
	else if (num == NOT_SURROUND_WALL)
		ft_printf ("Error\nis_not_surrounded_wall\n");
	else if (num == MAP_NAME_ERROR)
		ft_printf ("Error\nwrong_map_name\n");
	else if (num == MAP_IS_EMPTY)
		ft_printf ("Error\nmap_is_empty\n");
	else if (num == MAP_SIZE_ERROR)
		ft_printf ("Error\nmap_size_is_invalid");
	else if (num == NOT_PLATABLE)
		ft_printf ("Error\nnot_playable\n");
	exit (1);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;
	t_move	move;
	char	**map_data;
	// int		i;

	// i = 0;
	if (argc != 2)
		print_error (ARG_ERROR);
	fd = open (argv[1], O_RDONLY);
	if (fd < 0)
		print_error (OPEN_ERROR);
	init_map_data (&map);
	map.str = read_map (argv, fd, &map);
	map_data = copy_map (&map);
	if (map.width > INT_MAX / map.height)
		print_error (MAP_SIZE_ERROR);
	// while (map_data[i])
	// {
	// 	ft_printf ("%s\n", map.str[i]);
	// 	i++;
	// }
	// ft_printf ("--------------------\n");
	close (fd);
	check_map (argv, &map);
	init_move_data (&move);
	check_path (map_data, &map, &move);
	// i = 0;
	// while (map.str[i])
	// {
	// 	ft_printf ("%s\n", map.str[i]);
	// 	i++;
	// }
	// init_list(list);
	return (0);
}