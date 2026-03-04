/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:05:00 by chguerre          #+#    #+#             */
/*   Updated: 2026/03/04 17:54:57 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	handle_key(int keysym, t_game *game)
{
	if (keysym == KEY_W)
	{
		move_player(game, game->p_y - 1, game->p_x);
	}
	else if (keysym == KEY_S)
	{
		move_player(game, game->p_y + 1, game->p_x);
	}
	else if (keysym == KEY_A)
	{
		move_player(game, game->p_y, game->p_x - 1);
	}
	else if (keysym == KEY_D)
	{
		move_player(game, game->p_y, game->p_x + 1);
	}
	else if (keysym == KEY_ESC)
	{
		close_window(game);
	}
	return (1);
}
