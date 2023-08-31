/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:30:33 by tofujiwa          #+#    #+#             */
/*   Updated: 2023/02/26 20:30:33 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>
# include <inttypes.h>
# include <limits.h>

ssize_t	ft_putchar(unsigned char c);
int		ft_printf(const char *format, ...);
ssize_t	ft_putpointer(uintptr_t point);
ssize_t	ft_puthexa(unsigned int num);
ssize_t	ft_puthexa_up(unsigned int num);
ssize_t	ft_putnbr(int nb);
ssize_t	ft_putuns(unsigned int num);
ssize_t	ft_putstr_n(char *str);

#endif