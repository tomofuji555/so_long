/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:09:02 by tofujiwa          #+#    #+#             */
/*   Updated: 2023/02/26 17:09:02 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	nbr_count(int nb)
{
	ssize_t		size;
	long		n;

	n = nb;
	size = 0;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void	ft_sub_putnbr(int nb)
{
	long	n;

	n = (long)nb;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		ft_sub_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}

ssize_t	ft_putnbr(int nb)
{
	ssize_t	size;

	size = 0;
	if (nb == 0)
		size = write (1, "0", 1);
	else
	{
		size = nbr_count (nb);
		ft_sub_putnbr (nb);
	}
	return (size);
}
