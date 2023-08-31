/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:09:19 by tofujiwa          #+#    #+#             */
/*   Updated: 2023/02/26 17:09:19 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	hexa_up_counter(unsigned int num)
{
	ssize_t	size;

	size = 0;
	while (num > 0)
	{
		num = num / 16;
		size++;
	}
	return (size);
}

static void	ft_sub_puthexa_up(unsigned int num)
{
	char	c;

	c = 0;
	if (num > 0)
	{
		ft_sub_puthexa_up (num / 16);
		c = (num % 16);
		if (c >= 0 && c <= 9)
			ft_putchar (c + '0');
		else if (10 <= c && c <= 16)
			ft_putchar (c - 10 + 'A');
	}
}

ssize_t	ft_puthexa_up(unsigned int num)
{
	ssize_t	size;

	size = 0;
	if (num == 0)
		size = write (1, "0", 1);
	else
	{
		size = hexa_up_counter (num);
		ft_sub_puthexa_up (num);
	}
	return (size);
}
