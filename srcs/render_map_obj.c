/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:40:52 by wvan-der          #+#    #+#             */
/*   Updated: 2023/11/10 16:58:37 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_wall(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->img.wall, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_ground(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->img.ground, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_player(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->img.player, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_coin(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->img.coin, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_exit(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->img.exit, x * TILE_SIZE, y * TILE_SIZE);
}
