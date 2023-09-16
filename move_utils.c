/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:53:28 by tofujiwa          #+#    #+#             */
/*   Updated: 2023/09/16 15:08:05 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player_pos(t_player *player, int flag)
{
	if (flag == UP)
		(player->move.p_y)--;
	else if (flag == DOWN)
		(player->move.p_y)++;
	else if (flag == LEFT)
		(player->move.p_x)--;
	else
		(player->move.p_x)++;
}

void	move_to_tile(t_map *map, t_player *player, int flag)
{
	if (player->move.p_y == map->epost.e_y
		&& player->move.p_x == map->epost.e_x)
		map->str[player->move.p_y][player->move.p_x] = 'E';
	else
		map->str[player->move.p_y][player->move.p_x] = '0';
	update_player_pos(player, flag);
	map->str[player->move.p_y][player->move.p_x] = 'P';
}

void	move_to_collect(t_map *map, t_player *player, int flag)
{
	if (player->move.p_y == map->epost.e_y
		&& player->move.p_x == map->epost.e_x)
		map->str[player->move.p_y][player->move.p_x] = 'E';
	else
		map->str[player->move.p_y][player->move.p_x] = '0';
	update_player_pos(player, flag);
	map->str[player->move.p_y][player->move.p_x] = 'P';
	map->collect_c++;
}

void	move_to_exit(t_map *map, t_player *player, int flag)
{
	map->str[player->move.p_y][player->move.p_x] = '0';
	update_player_pos(player, flag);
	map->str[player->move.p_y][player->move.p_x] = 'P';
}
