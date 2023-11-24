/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:13:09 by wvan-der          #+#    #+#             */
/*   Updated: 2023/11/10 16:56:44 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_border(t_game *game)
{
	if (check_first_row(game) == 0)
		return (put_error("Map is invalind because of first row."), 0);
	if (check_if_square(game) == 0)
		return (put_error("Map is not square."), 0);
	if (check_last_row(game) == 0)
		return (put_error("Map is invalid because of last row."), 0);
	if (check_first_last_collum(game) == 0)
		return (put_error("Map is invalid bc of first or last collum."), 0);
	return (1);
}

int	check_first_row(t_game *game)
{
	int	x;

	x = 0;
	while (game->map[0][x])
	{
		if (game->map[0][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	check_if_square(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	while (y <= game->y_max)
	{
		while (game->map[y][x])
		{
			x++;
		}
		if (x != game->x_max + 1)
			return (0);
		x = 0;
		y++;
	}
	return (1);
}

int	check_last_row(t_game *game)
{
	int	x;

	x = 0;
	while (game->map[game->y_max][x])
	{
		if (game->map[game->y_max][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	check_first_last_collum(t_game *game)
{
	int	y;

	y = 1;
	while (y < game->y_max)
	{
		if (game->map[y][0] != '1' || game->map[y][game->x_max] != '1')
			return (0);
		y++;
	}
	return (1);
}
