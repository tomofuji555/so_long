/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:29:48 by tofujiwa          #+#    #+#             */
/*   Updated: 2023/09/10 15:29:48 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	where_is_P(char **map_data, t_map *map, t_move *move)
{
	int	i;
	int	j;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map_data[i][j] == 'P')
			{
				move->p_x = j;
				move->p_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	check_wasd(char **map_data, int y, int x)
{
	if (map_data[y][x] != '1')
	{
		map_data[y][x] = '1';
		check_wasd (map_data, y - 1, x);
		check_wasd (map_data, y + 1, x);
		check_wasd (map_data, y, x - 1);
		check_wasd (map_data, y, x + 1);
	}
}

static int	is_done_all_path(char **map_data, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map_data[i][j] == 'E' || map_data[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_path (char **map_data, t_map *map, t_move *move)
{
	where_is_P (map_data, map, move);
	check_wasd (map_data, move->p_y, move->p_x);
	is_done_all_path (map_data, map);
	if (!is_done_all_path (map_data, map))
		print_error (NOT_PLATABLE);
}