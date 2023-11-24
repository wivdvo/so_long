/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:28:47 by wvan-der          #+#    #+#             */
/*   Updated: 2023/11/10 16:58:30 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init_wall(t_game *game)
{
	game->img.wall = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/wall.xpm",
			&game->img.width, &game->img.height);
	if (game->img.wall == NULL)
	{
		mlx_destroy_display(game->mlx_ptr);
		return (put_error("MLX file to image failed."), 0);
	}
	return (1);
}

int	init_coin(t_game *game)
{
	game->img.coin = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/coin.xpm",
			&game->img.width, &game->img.height);
	if (game->img.coin == NULL)
	{
		mlx_destroy_display(game->mlx_ptr);
		return (put_error("MLX file to image failed."), 0);
	}
	return (1);
}

int	init_player(t_game *game)
{
	game->img.player = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/player.xpm", &game->img.width, &game->img.height);
	if (game->img.player == NULL)
	{
		mlx_destroy_display(game->mlx_ptr);
		return (put_error("MLX file to image failed."), 0);
	}
	return (1);
}

int	init_exit(t_game *game)
{
	game->img.exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/exit.xpm", &game->img.width, &game->img.height);
	if (game->img.exit == NULL)
	{
		mlx_destroy_display(game->mlx_ptr);
		return (put_error("MLX file to image failed."), 0);
	}
	return (1);
}

int	init_ground(t_game *game)
{
	game->img.ground = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/ground.xpm", &game->img.width, &game->img.height);
	if (game->img.ground == NULL)
	{
		mlx_destroy_display(game->mlx_ptr);
		return (put_error("MLX file to image failed."), 0);
	}
	return (1);
}
