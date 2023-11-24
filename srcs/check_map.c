/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:34:43 by wvan-der          #+#    #+#             */
/*   Updated: 2023/11/17 11:14:26 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_map(char *path, t_game *game)
{
	int		fd;

	fd = open(path, O_RDWR);
	if (fd < 0)
		return (0);
	if (make_map_str(game, fd) == 0)
		return (put_error("Malloc failed."), 0);
	if (check_amount_chars(game) == 0)
		return (0);
	if (split_map(game) == 0)
		return (0);
	if (check_border(game) == 0)
		return (0);
	if (check_path(game) == 0)
		return (0);
	return (1);
}

int	make_map_str(t_game *game, int fd)
{
	char	*line;
	int		y;
	char	*temp;

	game->map_str = NULL;
	y = 0;
	while (game->flag)
	{
		line = get_next_line(fd);
		if (line)
		{
			temp = ft_strjoin(game->map_str, line);
			free(line);
			free(game->map_str);
			game->map_str = temp;
			if (!game->map_str)
				return (0);
		}
		else
			game->flag = 0;
		y++;
	}
	game->y_max = y - 2;
	return (1);
}

int	allowed_chars(int c)
{
	if (c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'X' || c == '\n')
		return (1);
	else
		return (0);
}

int	check_amount_chars(t_game *game)
{
	int	i;
	int	player_count;
	int	exit_count;

	i = 0;
	player_count = 0;
	exit_count = 0;
	if (game->map_str == NULL)
		return (0);
	while (game->map_str[i])
	{
		if (allowed_chars(game->map_str[i]) == 0)
			return (put_error("Invalid char in map."), 0);
		if (game->map_str[i] == 'P')
			player_count++;
		if (game->map_str[i] == 'X')
			exit_count++;
		if (game->map_str[i] == 'C')
			game->coin_count++;
		i++;
	}
	if (player_count != 1 || exit_count != 1 || game->coin_count == 0)
		return (put_error("Wrong amount of game Objectives."), 0);
	return (1);
}

int	split_map(t_game *game)
{
	game->map = ft_split(game->map_str);
	if (!game->map)
		return (free(game->map_str), 0);
	while (game->map[0][game->x_max])
		game->x_max++;
	game->x_max--;
	return (1);
}
