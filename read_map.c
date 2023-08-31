/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:24:49 by tofujiwa          #+#    #+#             */
/*   Updated: 2023/08/31 17:06:20 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_double_array(char *str, size_t i)
{
	char	**p;

	p = (char **)malloc(sizeof (char *) * i);
	
}

void	read_map(int fd)
{
	char	*str;
	size_t	i;

	i = 0;
	while (1)
	{
		str = get_next_line (fd);
		if (str == NULL)
			break ;
		i++;
	}
	
}