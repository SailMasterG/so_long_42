/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 18:07:36 by chguerre          #+#    #+#             */
/*   Updated: 2026/03/04 17:07:37 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"
/**
 * @brief Create a canvas object
 *
 * @param game
 * @return int
 */
int	create_canvas(t_game *game)
{
	t_img	*canva;

	canva = &game->canvas;
	canva->img_w = game->win_w;
	canva->img_h = game->win_h;
	canva->img_ptr = mlx_new_image(game->mlx_ptr, canva->img_w, canva->img_h);
	if (!canva->img_ptr)
		return (0);
	canva->addr = mlx_get_data_addr(canva->img_ptr, &canva->bbp,
			&canva->line_len, &canva->endian);
	return (1);
}

/**
 * @brief For init the game struct and call de render of canvas & assets
 *is his funtion failed, the game stop instantally
 * @param game
 * @return int
 */
int	game_init(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (0);
	game->win_h = game->map.rows * TILE_S;
	game->win_w = game->map.cols * TILE_S;
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->win_w, game->win_h,
			"Solong");
	if (!game->win_ptr)
		return (0);
	game->moves = 0;
	game->map.exit = 0;
	game->prev_tile = '0';
	game->c_token = 0;
	if (!create_canvas(game))
		return (0);
	if (!generate_assets(game))
		return (0);
	return (1);
}
