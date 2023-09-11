/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:37:09 by tofujiwa          #+#    #+#             */
/*   Updated: 2023/09/02 17:37:09 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_name_correct(char *argv)
{
	size_t	i;

	i = ft_strlen (argv);
	if (i < 5)
		return (0);
	if (argv[i - 1] != 'r' || argv[i - 2] != 'e' || argv[i - 3] != 'b'
		|| argv[i - 4] != '.')
		return (0);
	return (1);
}

static void	count_elements(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->str[i])
	{
		j = 0;
		while (map->str[i][j])
		{
			if (map->str[i][j] == 'P')
				map->count_p = map->count_p + 1;
			else if (map->str[i][j] == 'C')
				map->count_c = map->count_c + 1;
			else if (map->str[i][j] == 'E')
				map->count_e = map->count_e + 1;
			else if (map->str[i][j] != '0' && map->str[i][j] != '1')
				print_error (ELEMENTS_ERROR);
			j++;
		}
		i++;
	}
}

static int	is_surrounded_wall(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->str[i])
	{
		j = 0;
		while (map->str[i][j])
		{
			if (map->str[i][j] != '1' && i == 0)
				return (0);
			if (map->str[i][j] != '1' && i == (map->height - 1))
				return (0);
			if (map->str[i][j] != '1' && j == 0)
				return (0);
			if (map->str[i][j] != '1' && j == (map->width - 1))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	is_rectangle(t_map *map)
{
	int	i;
	int	j;
	int	save;

	i = 1;
	j = 0;
	while (map->str[0][j])
		j++;
	save = j;
	while (map->str[i])
	{
		j = 0;
		while (map->str[i][j])
			j++;
		if (save != j)
			return (0);
		i++;
	}
	return (1);
}

void	check_map(char **argv, t_map *map)
{
	count_elements (map);
	if (!map_name_correct(argv[1]))
		print_error (MAP_NAME_ERROR);
	else if (map->height == map->width || !is_rectangle (map))
		print_error (NOT_RECTANGLE);
	else if (map->count_p != 1 || map->count_e != 1 || map->count_c < 1)
		print_error (ELEMENTS_ERROR);
	else if (!is_surrounded_wall(map))
		print_error (NOT_SURROUND_WALL);
}
