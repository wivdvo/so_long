/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:24:43 by wvan-der          #+#    #+#             */
/*   Updated: 2023/11/10 16:56:23 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_path(t_game *game)
{
	find_player(game);
	check_position(game, game->x_player, game->y_player);
	if (check_valid(game) == 0)
		return (0);
	return (1);
}

void	find_player(t_game *game)
{
	game->x_player = 0;
	game->y_player = 0;
	game->y = 0;
	while (game->y <= game->y_max)
	{
		game->x = 0;
		while (game->x <= game->x_max)
		{
			if (game->map[game->y][game->x] == 'P')
			{
				game->x_player = game->x;
				game->y_player = game->y;
				return ;
			}
			game->x++;
		}
		game->y++;
	}
}

void	check_position(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'P')
	{
		game->map[y][x] = 'p';
		move_check_position(game, x, y);
	}
	if (game->map[y][x] == '0')
	{
		game->map[y][x] = 'o';
		move_check_position(game, x, y);
	}
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = 'c';
		move_check_position(game, x, y);
	}
	if (game->map[y][x] == 'X')
		game->map[y][x] = 'x';
}

void	move_check_position(t_game *game, int x, int y)
{
	check_position(game, x + 1, y);
	check_position(game, x, y + 1);
	check_position(game, x - 1, y);
	check_position(game, x, y - 1);
}

int	check_valid(t_game *game)
{
	game->y = 0;
	while (game->y <= game->y_max)
	{
		game->x = 0;
		while (game->x <= game->x_max)
		{
			if (game->map[game->y][game->x] == 'C')
			{
				put_error("Map contains unreachable coin(s).");
				return (0);
			}
			if (game->map[game->y][game->x] == 'X')
			{
				put_error("The exit ureachable.");
				return (0);
			}
			game->x++;
		}
		game->y++;
	}
	return (1);
}
