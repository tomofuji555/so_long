/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_finish.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:52:29 by tofujiwa          #+#    #+#             */
/*   Updated: 2023/09/15 21:01:20 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_game(t_data *data_ptr)
{
	printf("%d\nGame Clear!!\n", ++(data_ptr->img.player.move_count));
	free_double (data_ptr->map.str);
	close_game(data_ptr, TRUE);
}

void	close_game(t_data *data_ptr, int flag)
{
	destroy_data(data_ptr);
	if (flag == FALSE)
		exit(FALSE);
	else
		exit(TRUE);
}

void	destroy_data(t_data *data_ptr)
{
	destroy_imgs(data_ptr->mlx, &(data_ptr->img));
	if (data_ptr->window != NULL)
		mlx_destroy_window(data_ptr->mlx, data_ptr->window);
}

void	destroy_imgs(void *mlx, t_img *img)
{
	if (img->player.img != NULL)
		mlx_destroy_image(mlx, img->player.img);
	if (img->collect_img != NULL)
		mlx_destroy_image(mlx, img->collect_img);
	if (img->wall_img != NULL)
		mlx_destroy_image(mlx, img->wall_img);
	if (img->tile_img != NULL)
		mlx_destroy_image(mlx, img->tile_img);
	if (img->exit_img != NULL)
		mlx_destroy_image(mlx, img->exit_img);
}

void	free_double(char **str)
{
	int	i;

	if (str)
	{
		i = 0;
		while (str[i])
		{
			free (str[i]);
			i++;
		}
		free (str);
	}
}
