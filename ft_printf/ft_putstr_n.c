/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:09:56 by tofujiwa          #+#    #+#             */
/*   Updated: 2023/02/26 17:09:56 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putstr_n(char *str)
{
	ssize_t	size;

	size = 0;
	if (str == NULL)
	{
		size = write (1, "(null)", 6);
		return (size);
	}
	while (*str)
	{
		size += write (1, str, 1);
		str++;
	}
	return (size);
}
