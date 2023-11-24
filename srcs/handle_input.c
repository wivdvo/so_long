/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:39:40 by wvan-der          #+#    #+#             */
/*   Updated: 2023/11/13 18:00:49 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	handle_input(int keysym, t_game *game)
{
	game->move_count++;
	ft_printf("%d moves\n", game->move_count);
	if (game->coin_count == 0 && game->exit_flag == 0)
		open_exit(game);
	if (keysym == XK_Escape)
		close_window(game);
	if (keysym == XK_w || keysym == XK_Up)
		move_up(game);
	if (keysym == XK_d || keysym == XK_Right)
		move_right(game);
	if (keysym == XK_s || keysym == XK_Down)
		move_down(game);
	if (keysym == XK_a || keysym == XK_Left)
		move_left(game);
	return (1);
}

void	move_up(t_game *game)
{
	game->map[game->y_player][game->x_player] = 'o';
	game->y_player -= 1;
	if (game->map[game->y_player][game->x_player] == '1'
		|| game->map[game->y_player][game->x_player] == 'x')
		game->y_player += 1;
	if (game->map[game->y_player][game->x_player] == 'c')
		game->coin_count--;
	if (game->map[game->y_player][game->x_player] == 'X')
		close_window(game);
	game->map[game->y_player][game->x_player] = 'p';
	render_map(game);
}

void	move_right(t_game *game)
{
	game->map[game->y_player][game->x_player] = 'o';
	game->x_player += 1;
	if (game->map[game->y_player][game->x_player] == '1'
		|| game->map[game->y_player][game->x_player] == 'x')
		game->x_player -= 1;
	if (game->map[game->y_player][game->x_player] == 'c')
		game->coin_count--;
	if (game->map[game->y_player][game->x_player] == 'X')
		close_window(game);
	game->map[game->y_player][game->x_player] = 'p';
	render_map(game);
}

void	move_down(t_game *game)
{
	game->map[game->y_player][game->x_player] = 'o';
	game->y_player += 1;
	if (game->map[game->y_player][game->x_player] == '1'
		|| game->map[game->y_player][game->x_player] == 'x')
		game->y_player -= 1;
	if (game->map[game->y_player][game->x_player] == 'c')
		game->coin_count--;
	if (game->map[game->y_player][game->x_player] == 'X')
		close_window(game);
	game->map[game->y_player][game->x_player] = 'p';
	render_map(game);
}

void	move_left(t_game *game)
{
	game->map[game->y_player][game->x_player] = 'o';
	game->x_player -= 1;
	if (game->map[game->y_player][game->x_player] == '1'
		|| game->map[game->y_player][game->x_player] == 'x')
		game->x_player += 1;
	if (game->map[game->y_player][game->x_player] == 'c')
		game->coin_count--;
	if (game->map[game->y_player][game->x_player] == 'X')
		close_window(game);
	game->map[game->y_player][game->x_player] = 'p';
	render_map(game);
}
