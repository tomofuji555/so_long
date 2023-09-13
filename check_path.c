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

static void	where_is_p(char **map_data, t_map *map, t_move *move)
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

void	recursive_dfs(char **map_data, int y, int x)
{
	if (map_data[y][x] != '1')
	{
		map_data[y][x] = '1';
		ft_printf ("y = %d, x = %d\n", y, x);
		recursive_dfs (map_data, y - 1, x);
		recursive_dfs (map_data, y + 1, x);
		recursive_dfs (map_data, y, x - 1);
		recursive_dfs (map_data, y, x + 1);
	}
}

static int	is_collect_exit(char **map_data, t_map *map)
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

void	check_path(char **map_data, t_map *map, t_move *move)
{
	where_is_p (map_data, map, move);
	recursive_dfs (map_data, move->p_y, move->p_x);
	is_collect_exit (map_data, map);
	if (!is_collect_exit (map_data, map))
		print_error (MAP_ERROR);
}
