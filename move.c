/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:11:43 by tofujiwa          #+#    #+#             */
/*   Updated: 2023/09/16 15:07:55 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	get_next_val(t_map map, t_move move, int flag)
{
	if (flag == UP)
		return (map.str[move.p_y - 1][move.p_x]);
	else if (flag == DOWN)
		return (map.str[move.p_y + 1][move.p_x]);
	else if (flag == LEFT)
		return (map.str[move.p_y][move.p_x - 1]);
	else
		return (map.str[move.p_y][move.p_x + 1]);
}

int	move(t_map *map, t_player *player, int flag)
{
	char	next_val;

	next_val = get_next_val(*map, player->move, flag);
	if (next_val == '1')
		return (0);
	else if (next_val == '0')
		move_to_tile(map, player, flag);
	else if (next_val == 'C')
		move_to_collect(map, player, flag);
	else if (next_val == 'E' && map->collect_c != map->count_c)
		move_to_exit(map, player, flag);
	else if (next_val == 'E' && map->collect_c == map->count_c)
		return (1);
	ft_printf("%d\n", ++(player->move_count));
	return (0);
}
