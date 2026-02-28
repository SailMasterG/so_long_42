/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 18:07:36 by chguerre          #+#    #+#             */
/*   Updated: 2026/02/28 22:29:51 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "mlx.h"






int game_init(t_game *game)
{
    t_img *canva;

    canva = &game->canvas;
    game->mlx_ptr = mlx_init();
    if(!game->mlx_ptr)
        return (0);
    game->win_h = game->map.rows * TILE_S;
    game->win_w = game->map.cols * TILE_S;
    game->win_ptr = mlx_new_window(game->mlx_ptr, game->win_w, game->win_h, "Solong");
    if(!game->win_ptr)
        return (0);
    game->p_x = 0;
    game->p_y = 0;
    game->moves = 0;
    canva->img_w = game->win_w;
    canva->img_h = game->win_h;
    canva->img_ptr = mlx_new_image(game->mlx_ptr, canva->img_w, canva->img_h);
    if(!canva->img_ptr)
        return (0);
    canva->addr = mlx_get_data_addr(canva->img_ptr, &canva->bbp, &canva->line_len, &canva->endian);
    if (!generate_assets(game))
        return (0);
    return (1);
}