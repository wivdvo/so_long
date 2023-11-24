/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:54:38 by wvan-der          #+#    #+#             */
/*   Updated: 2023/11/16 13:28:37 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	render(t_game *game)
{
	if (init_mlx(game) == 0)
		return (0);
	if (init_img(game) == 0)
		return (0);
	if (render_map(game) == 0)
		return (0);
	mlx_key_hook(game->win_ptr, handle_input, game);
	mlx_hook(game->win_ptr, 17, 0L, close_window, game);
	mlx_loop(game->mlx_ptr);
	return (1);
}

int	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		return (put_error("MLX init failed."), 0);
	game->win_ptr = mlx_new_window(game->mlx_ptr, TILE_SIZE * (game->x_max + 1),
			TILE_SIZE * (game->y_max + 1), "so_long");
	if (game->win_ptr == NULL)
	{
		mlx_destroy_display(game->mlx_ptr);
		return (put_error("MLX new window failed."), 0);
	}
	return (1);
}

int	close_window(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->img.wall);
	mlx_destroy_image(game->mlx_ptr, game->img.ground);
	mlx_destroy_image(game->mlx_ptr, game->img.coin);
	mlx_destroy_image(game->mlx_ptr, game->img.exit);
	mlx_destroy_image(game->mlx_ptr, game->img.player);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	ft_free_so_long(game);
	exit(0);
}
