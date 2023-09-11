/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:14:23 by tofujiwa          #+#    #+#             */
/*   Updated: 2023/09/11 18:14:23 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*strcpy_malloc(char *str, t_map *map)
{
	char	*rt;
	int		i;

	i = 0;
	rt = (char *)malloc(sizeof(char) * (map->width + 1));
	if (!rt)
		exit (1);
	while (i < map->width)
	{
		rt[i] = str[i];
		i++;
	}
	rt[i] = '\0';
	return (rt);
}

char	**copy_map(t_map *map)
{
	char	**map_data;
	int		i;

	i = 0;
	map_data = (char **)malloc(sizeof(char *) * (map->height) + 1);
	if (!map_data)
		exit (1);
	while (i < map->height)
	{
		map_data[i] = strcpy_malloc (map->str[i], map);
		i++;
	}
	map_data[i] = NULL;
	return (map_data);
}
