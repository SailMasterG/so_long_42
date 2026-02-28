/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 22:15:29 by chguerre          #+#    #+#             */
/*   Updated: 2026/02/28 21:28:26 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
void generate_tile(t_game *game, char tile, int x, int y)
{
	sprite(game, game->floor, TILE_S * x, TILE_S * y);
	if (tile == '1')
		sprite(game, game->wall, TILE_S * x, TILE_S * y);
	else if (tile == 'P')
	{
		sprite(game, game->player, TILE_S * x, TILE_S * y);
		game->p_x = x;
		game->p_y = y;
	}
	else if (tile == 'C')
		sprite(game, game->colection, TILE_S * x, TILE_S * y);
	else if (tile == 'E')
		sprite(game, game->img_exit, TILE_S * x, TILE_S * y);
}

int render_map(t_game *game)
{
	int x;
	int y;
	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			printf("Renderizando tile en posición (%d, %d) con valor '%c'\n", y, x, game->map.grid[y][x]);
			generate_tile(game, game->map.grid[y][x], x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->canvas.img_ptr, 0, 0);
	/* mlx_destroy_image(game->mlx_ptr, game->canvas.img_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr); */
	return (1);
}