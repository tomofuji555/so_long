/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:25:38 by tofujiwa          #+#    #+#             */
/*   Updated: 2023/09/11 20:19:43 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <fcntl.h>
#include <mlx.h>
#include "get_next_line/get_next_line.h"
#include "ft_printf/ft_printf.h"

enum {
	ARG_ERROR = 1001,
	OPEN_ERROR = 1002,
	MALLOC_ERROR = 1003,
	NOT_RECTANGLE = 1004,
	ELEMENTS_ERROR = 1005,
	NOT_SURROUND_WALL = 1006,
	MAP_NAME_ERROR = 1007,
	MAP_IS_EMPTY = 1008,
	MAP_SIZE_ERROR = 1009,
	NOT_PLATABLE = 1010
};

enum {
	W = 13,
	S = 1,
	A = 0,
	D = 2,
	ESC = 53
};

// enum {
// 	ON_KEYDOWN = 2,
// 	ON_KEYUP = 3,
// 	ON_MOUSEDOWN = 4,
// 	ON_MOUSEUP = 5,
// 	ON_MOUSEMOVE = 6,
// 	ON_EXPOSE = 12,
// 	ON_DESTROY = 17
// };

typedef struct s_map
{
	int		height;
	int		width;
	int		max;
	int		count_0;
	int		count_1;
	int		count_p;
	int		count_c;
	int		count_e;
	char	**str;
}	t_map;

typedef struct s_move
{
	int	p_x;
	int	p_y;
}	t_move;

typedef struct s_stack
{
	int		tail;
	t_move	*data;
	int		max;
}	t_stack;


// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }	t_data;

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }	t_vars;

char	**read_map(char **argv, int fd, t_map *map);
void	init_map_data(t_map *map);
void	init_move_data(t_move *move);
void	init_stack(t_stack *stck);
void	print_error(int num);
char	**copy_map(t_map *map);
void	check_map(char **argv, t_map *map);
void	check_wasd(char **map_data, int y, int x);
void	check_path (char **map_data, t_map *map, t_move *move);
// void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
// void	mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param);

#endif