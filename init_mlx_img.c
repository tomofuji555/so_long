/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:55:27 by tofujiwa          #+#    #+#             */
/*   Updated: 2023/09/16 16:17:57 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_null_with_data(t_data *data_ptr)
{
	data_ptr->mlx = NULL;
	data_ptr->window = NULL;
	data_ptr->img.player.img = NULL;
	data_ptr->img.collect_img = NULL;
	data_ptr->img.wall_img = NULL;
	data_ptr->img.tile_img = NULL;
	data_ptr->img.exit_img = NULL;
}

void	init_imgs(t_data *data_ptr)
{
	data_ptr->img.player.img = mlx_xpm_file_to_image(data_ptr->mlx, \
		"image/player.xpm", &data_ptr->img.width, &data_ptr->img.height);
	if (data_ptr->img.player.img == NULL)
		close_game(data_ptr, FALSE);
	data_ptr->img.collect_img = mlx_xpm_file_to_image(data_ptr->mlx, \
		"image/collect.xpm", &data_ptr->img.width, &data_ptr->img.height);
	if (data_ptr->img.collect_img == NULL)
		close_game(data_ptr, FALSE);
	data_ptr->img.tile_img = mlx_xpm_file_to_image(data_ptr->mlx, \
		"image/tile.xpm", &data_ptr->img.width, &data_ptr->img.height);
	if (data_ptr->img.tile_img == NULL)
		close_game(data_ptr, FALSE);
	data_ptr->img.wall_img = mlx_xpm_file_to_image(data_ptr->mlx, \
		"image/wall.xpm", &data_ptr->img.width, &data_ptr->img.height);
	if (data_ptr->img.wall_img == NULL)
		close_game(data_ptr, FALSE);
	data_ptr->img.exit_img = mlx_xpm_file_to_image(data_ptr->mlx, \
		"image/exit.xpm", &data_ptr->img.width, &data_ptr->img.height);
	if (data_ptr->img.exit_img == NULL)
		close_game(data_ptr, FALSE);
}

void	init_mlx_img(t_data *data_ptr)
{
	fill_null_with_data(data_ptr);
	data_ptr->mlx = mlx_init();
	if (data_ptr->mlx == NULL)
		close_game(data_ptr, FALSE);
	data_ptr->img.player.move_count = 0;
	init_imgs(data_ptr);
	data_ptr->window = mlx_new_window(data_ptr->mlx, data_ptr->map.width * \
		data_ptr->img.width, data_ptr->map.height * data_ptr->img.height, \
		"so_long");
	if (data_ptr->window == NULL)
		close_game(data_ptr, FALSE);
}
