/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:15:20 by wvan-der          #+#    #+#             */
/*   Updated: 2023/11/13 17:42:52 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_map(t_game *game)
{
	game->y = 0;
	while (game->y <= game->y_max)
	{
		game->x = 0;
		while (game->x <= game->x_max)
		{
			ft_printf("%c", game->map[game->y][game->x]);
			game->x++;
		}
		ft_printf("\n");
		game->y++;
	}
}

void	put_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	write(2, "\n", 1);
}

int	open_exit(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->exit_flag = 1;
	while (y <= game->y_max)
	{
		x = 0;
		while (x <= game->x_max)
		{
			if (game->map[y][x] == 'x')
			{
				game->map[y][x] = 'X';
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_free_so_long(t_game *game)
{
	int	y;

	y = game->y_max;
	if (game->map_str)
	{
		free(game->map_str);
	}
	if (game->map)
	{
		while (y >= 0)
		{
			if (game->map[y])
				free(game->map[y]);
			y--;
		}
		free(game->map);
	}
}
