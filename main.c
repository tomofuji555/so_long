/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:32:38 by tofujiwa          #+#    #+#             */
/*   Updated: 2023/08/31 15:55:57 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int	fd;

	if (argc <= 1)
		exit (1);
	fd = open (argv[1], O_RDONLY);
	if (fd < 0)
		ft_printf ("Error\nopen_error");
	read_map(fd);
}