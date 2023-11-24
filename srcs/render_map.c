/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:35:31 by wvan-der          #+#    #+#             */
/*   Updated: 2023/11/10 16:58:41 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y <= game->y_max)
	{
		x = 0;
		while (x <= game->x_max)
		{
			if (game->map[y][x] == '1')
				render_wall(game, x, y);
			if (game->map[y][x] == 'o')
				render_ground(game, x, y);
			if (game->map[y][x] == 'p')
				render_player(game, x, y);
			if (game->map[y][x] == 'c')
				render_coin(game, x, y);
			if (game->map[y][x] == 'x' || game->map[y][x] == 'X')
				render_exit(game, x, y);
			x++;
		}
		y++;
	}
	return (1);
}
