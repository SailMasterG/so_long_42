/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 22:15:29 by chguerre          #+#    #+#             */
/*   Updated: 2026/03/04 17:49:43 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	generate_tile(t_game *game, char tile, int x, int y)
{
	sprite(game, game->floor, TILE_S * x, TILE_S * y);
	if (tile == '1')
		sprite(game, game->wall, TILE_S * x, TILE_S * y);
	else if (tile == 'P')
	{
		if (game->map.exit == 1)
			sprite(game, game->player_win, TILE_S * x, TILE_S * y);
		else
			sprite(game, game->player, TILE_S * x, TILE_S * y);
		game->p_x = x;
		game->p_y = y;
	}
	else if (tile == 'C')
		sprite(game, game->colection, TILE_S * x, TILE_S * y);
	else if (tile == 'E')
	{
		if (game->map.grid[game->p_y][game->p_x] == 'E')
		{
			sprite(game, game->img_exit, TILE_S * x, TILE_S * y);
			sprite(game, game->player, TILE_S * x, TILE_S * y);
		}
		else
			sprite(game, game->img_exit, TILE_S * x, TILE_S * y);
	}
}

int	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			generate_tile(game, game->map.grid[y][x], x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->canvas.img_ptr, 0, 0);
	contador_moves(game);
	return (1);
}
