/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:24:49 by tofujiwa          #+#    #+#             */
/*   Updated: 2023/09/11 20:41:08 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	until_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

static void	count_height(int fd, t_map *map)
{
	char	*str;
	int		i;

	i = 0;
	while (1)
	{
		str = get_next_line (fd);
		if (str == NULL)
			break ;
		(map->height) = (map->height) + 1;
		i++;
	}
	if (i == 0 && str == NULL)
		print_error (MAP_IS_EMPTY);
	free (str);
	close (fd);
}

char	**read_map(char **argv, int fd, t_map *map)
{
	char		**d_map;
	int			i;
	int			j;

	i = 0;
	j = 0;
	count_height (fd, map);
	fd = open (argv[1], O_RDONLY);
	d_map = (char **)malloc(sizeof (char *) * ((map->height) + 1));
	if (!d_map)
		print_error (MALLOC_ERROR);
	while (i < (map->height))
	{
		d_map[i] = get_next_line (fd);
		j = until_newline(d_map[i]);
		d_map[i][j] = '\0';
		i++;
	}
	d_map[i] = NULL;
	map->width = j;
	map->height = i;
	close (fd);
	return (d_map);
}
