/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:06:53 by tofujiwa          #+#    #+#             */
/*   Updated: 2023/09/15 18:43:32 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_data *data_ptr)
{
	int	i;
	int	j;

	i = 0;
	while (i < data_ptr->map.height)
	{
		j = 0;
		while (j < data_ptr->map.width)
		{
			if (data_ptr->map.str[i][j] == 'E')
			{
				data_ptr->map.epost.e_y = i;
				data_ptr->map.epost.e_x = j;
			}
			if (data_ptr->map.str[i][j] == 'P')
			{
				data_ptr->img.player.move.p_y = i;
				data_ptr->img.player.move.p_x = j;
			}
			render_img(data_ptr, i, j);
			j++;
		}
		i++;
	}
}

void	render_img(t_data *data_ptr, int y, int x)
{
	if (data_ptr->map.str[y][x] == '0')
		mlx_put_image_to_window(data_ptr->mlx, data_ptr->window, data_ptr->\
		img.tile_img, data_ptr->img.width * x, data_ptr->img.height * y);
	if (data_ptr->map.str[y][x] == '1')
		mlx_put_image_to_window(data_ptr->mlx, data_ptr->window, data_ptr->\
		img.wall_img, data_ptr->img.width * x, data_ptr->img.height * y);
	if (data_ptr->map.str[y][x] == 'C')
		mlx_put_image_to_window(data_ptr->mlx, data_ptr->window, data_ptr->\
		img.collect_img, data_ptr->img.width * x, data_ptr->img.height * y);
	if (data_ptr->map.str[y][x] == 'E')
		mlx_put_image_to_window(data_ptr->mlx, data_ptr->window, data_ptr->\
		img.exit_img, data_ptr->img.width * x, data_ptr->img.height * y);
	if (data_ptr->map.str[y][x] == 'P')
	{
		if (data_ptr->img.player.move.p_y == data_ptr->map.epost.e_y
			&& data_ptr->img.player.move.p_x == data_ptr->map.epost.e_x)
			mlx_put_image_to_window(data_ptr->mlx, data_ptr->window, data_ptr->\
			img.exit_img, data_ptr->img.width * x, data_ptr->img.height * y);
		else
			mlx_put_image_to_window(data_ptr->mlx, data_ptr->window, data_ptr->\
			img.tile_img, data_ptr->img.width * x, data_ptr->img.height * y);
		mlx_put_image_to_window(data_ptr->mlx, data_ptr->window, data_ptr->\
		img.player.img, data_ptr->img.width * x, data_ptr->img.height * y);
	}
}
