/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:00:59 by wvan-der          #+#    #+#             */
/*   Updated: 2023/11/13 17:49:33 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	(void)argc;
	init_struct(&game);
	if (argc != 2)
		return (put_error("Needs path to map as argument!"), 1);
	if (check_map(argv[1], &game) == 0)
	{
		ft_free_so_long(&game);
		return (1);
	}
	if (render(&game) == 0)
	{
		ft_free_so_long(&game);
		return (1);
	}
}

void	init_struct(t_game *game)
{
	game->map = NULL;
	game->map_str = NULL;
	game->img.wall = NULL;
	game->img.ground = NULL;
	game->img.coin = NULL;
	game->img.player = NULL;
	game->img.exit = NULL;
	game->x_max = 0;
	game->y_max = 0;
	game->x = 0;
	game->y = 0;
	game->x_player = 0;
	game->y_player = 0;
	game->coin_count = 0;
	game->move_count = 0;
	game->shortest_path = 0;
	game->exit_flag = 0;
	game->flag = 1;
}
