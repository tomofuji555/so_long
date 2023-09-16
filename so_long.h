/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:25:38 by tofujiwa          #+#    #+#             */
/*   Updated: 2023/09/16 16:27:24 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"

# define STDERR 2

enum	e_map_error
{
	ARG_ERROR = 0,
	OPEN_ERROR = 1,
	MALLOC_ERROR = 2,
	MAP_ERROR = 3
};

enum	e_key_code
{
	KEY_W = 13,
	KEY_S = 1,
	KEY_A = 0,
	KEY_D = 2,
	KEY_ESC = 53
};

enum e_directon
{
	UP		= 0,
	DOWN	= 1,
	LEFT	= 2,
	RIGHT	= 3
};

enum e_bool
{
	FALSE	= 1,
	TRUE	= 0
};

typedef struct s_move
{
	int	p_x;
	int	p_y;
}	t_move;

typedef struct s_epost
{
	int	e_x;
	int	e_y;
}	t_epost;

typedef struct s_map
{
	int		height;
	int		width;
	int		count_p;
	int		count_c;
	int		collect_c;
	int		count_e;
	char	**str;
	t_epost	epost;
}	t_map;

typedef struct s_player
{
	void	*img;
	t_move	move;
	int		move_count;
}	t_player;

typedef struct s_img
{
	int			width;
	int			height;
	t_player	player;
	void		*collect_img;
	void		*wall_img;
	void		*tile_img;
	void		*exit_img;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*window;
	t_map	map;
	t_img	img;
}	t_data;

char	**read_map(char **argv, int fd, t_map *map);
void	init_relate_map(t_map *map, t_move *move);
void	ft_putstr_fd(char *s, int fd);
void	print_error(int num);
char	**copy_map(t_map *map);
void	check_map(char **argv, t_map *map);
void	recursive_dfs(char **map_data, int y, int x);
void	check_path(char **map_data, t_map *map, t_move *move);
void	init_mlx_img(t_data *data_ptr);
void	fill_null_with_data(t_data *data_ptr);
void	init_imgs(t_data *data_ptr);
void	render_map(t_data *data_ptr);
void	render_img(t_data *data_ptr, int y, int x);
char	get_next_val(t_map map, t_move move, int flag);
void	update_player_pos(t_player *player, int flag);
void	move_to_tile(t_map *map, t_player *player, int flag);
void	move_to_collect(t_map *map, t_player *player, int flag);
void	move_to_exit(t_map *map, t_player *player, int flag);
int		move(t_map *map, t_player *player, int flag);
void	clear_game(t_data *data_ptr);
void	close_game(t_data *data_ptr, int flag);
void	destroy_data(t_data *data_ptr);
void	destroy_imgs(void *mlx, t_img *img);
void	free_double(char **str);

#endif