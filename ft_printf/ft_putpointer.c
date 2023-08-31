/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:55:53 by tofujiwa          #+#    #+#             */
/*   Updated: 2023/03/02 14:18:38 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	point_counter(uintptr_t point)
{
	ssize_t	size;

	size = 0;
	while (point > 0)
	{
		point = point / 16;
		size++;
	}
	return (size);
}

static void	ft_sub_putpointer(uintptr_t point)
{
	char	c;

	c = 0;
	if (point > 0)
	{
		ft_sub_putpointer(point / 16);
		c = (point % 16);
		if (c >= 0 && c <= 9)
			ft_putchar (c + '0');
		if (10 <= c && c <= 16)
			ft_putchar (c - 10 + 'a');
	}
}

ssize_t	ft_putpointer(uintptr_t point)
{
	ssize_t	size;

	size = 0;
	size += write (1, "0x", 2);
	if (point == 0)
		size += write (1, "0", 1);
	else
	{
		size += point_counter (point);
		ft_sub_putpointer (point);
	}
	return (size);
}
