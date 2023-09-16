/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:20:33 by tofujiwa          #+#    #+#             */
/*   Updated: 2023/09/16 16:29:33 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	size_t	len;

	if (!s)
		return ;
	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		write (fd, &s[i], 1);
		i++;
	}
}

void	print_error(int num)
{
	if (num == ARG_ERROR)
		ft_putstr_fd ("Error\narg_is_invalid\n", STDERR);
	else if (num == OPEN_ERROR)
		ft_putstr_fd ("Error\nopen_error\n", STDERR);
	else if (num == MALLOC_ERROR)
		ft_putstr_fd ("Error\nmalloc_error\n", STDERR);
	else if (num == MAP_ERROR)
		ft_putstr_fd ("Error\nmap_error\n", STDERR);
	exit (FALSE);
}
