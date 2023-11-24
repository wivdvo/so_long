/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:38:10 by wvan-der          #+#    #+#             */
/*   Updated: 2023/11/10 16:58:34 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init_img(t_game *game)
{
	if (init_wall(game) == 0)
		return (0);
	if (init_coin(game) == 0)
		return (0);
	if (init_player(game) == 0)
		return (0);
	if (init_exit(game) == 0)
		return (0);
	if (init_ground(game) == 0)
		return (0);
	return (1);
}
