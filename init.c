/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:47:52 by tofujiwa          #+#    #+#             */
/*   Updated: 2023/09/08 14:47:52 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map_data(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->max = 0;
	map->count_0 = 0;
	map->count_1 = 0;
	map->count_p = 0;
	map->count_c = 0;
	map->count_e = 0;
}

void	init_move_data(t_move *move)
{
	move->p_x = 0;
	move->p_y = 0;
}

void	init_stack(t_stack *stack)
{
	stack->tail = -1;
	stack->max = 0;
}
