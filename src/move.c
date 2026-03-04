/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:42:41 by chguerre          #+#    #+#             */
/*   Updated: 2026/03/04 12:14:01 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	move_player(t_game *game, int new_y, int new_x)
{
	if (game->map.grid[new_y][new_x] == '1')
		return (0);
	if (game->map.grid[new_y][new_x] == 'C')
	{
		game->map.coins--;
		printf("coins: %d\n", game->map.coins);
		game->map.grid[new_y][new_x] = '0';
	}
	if (game->map.grid[new_y][new_x] == 'E')
	{
		if (game->map.coins == 0)
		{
			printf("¡Has ganado en %d movimientos!\n", game->moves + 1);
			close_window(game);
			return (1);
		}
		printf("La salida está cerrada.\n");
	}
	if (game->map.coins == 0)
		game->map.exit = 1;
	game->map.grid[game->p_y][game->p_x] = game->prev_tile;
	game->prev_tile = game->map.grid[new_y][new_x];
	game->p_y = new_y;
	game->p_x = new_x;
	if (game->map.grid[new_y][new_x] != 'E')
		game->map.grid[new_y][new_x] = 'P';
	game->moves++;
	render_map(game);
	return (1);
}
