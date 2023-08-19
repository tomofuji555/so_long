/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:23:15 by tofujiwa          #+#    #+#             */
/*   Updated: 2023/08/19 20:37:15 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	my_mlx_pixel_put(t_data *data, int y, int x, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

int main (void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		height;
	int		length;

	height = 0;
	length = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1080, 1080, "Hello world!"); //make_window
	img.img = mlx_new_image(mlx, 1080, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	while (length < 360)
	{
		height = 0;
		while (height < 1080)
		{
			my_mlx_pixel_put(&img, height, length, 0x0000FF00);
			height++;
		}
		length++;
	}
	while (length < 720)
	{
		height = 0;
		while (height < 1080)
		{
			my_mlx_pixel_put(&img, height, length, 0x00FF0000);
			height++;
		}
		length++;
	}
	while (length < 1080)
	{
		height = 0;
		while (height < 1080)
		{
			my_mlx_pixel_put(&img, height, length, 0x000000FF);
			height++;
		}
		length++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

// int	close(int keycode, t_vars *vars)
// {
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	return (0);
// }

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
// 	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
// 	mlx_loop(vars.mlx);
// }