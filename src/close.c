/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 21:56:40 by chguerre          #+#    #+#             */
/*   Updated: 2026/02/28 22:29:00 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int close_window(t_game *game)
{
     mlx_loop_end(game->mlx_ptr);
     return (0);
}

void free_resources(t_game *game)
{
    if (game->mlx_ptr)
    {
        free_sprites(game);
        if (game->canvas.img_ptr)
            mlx_destroy_image(game->mlx_ptr, game->canvas.img_ptr);
        if (game->win_ptr)
            mlx_destroy_window(game->mlx_ptr, game->win_ptr);
        mlx_destroy_display(game->mlx_ptr);
        free(game->mlx_ptr);
    }
    if (game->map.grid)
        free_matrix(game->map.grid);
}
void free_sprites(t_game *game)
{
    if (game->player.img_ptr)
        mlx_destroy_image(game->mlx_ptr, game->player.img_ptr);
    if (game->floor.img_ptr)
        mlx_destroy_image(game->mlx_ptr, game->floor.img_ptr);
    if (game->wall.img_ptr)
        mlx_destroy_image(game->mlx_ptr, game->wall.img_ptr);
    if (game->img_exit.img_ptr)
        mlx_destroy_image(game->mlx_ptr, game->img_exit.img_ptr);
    if (game->colection.img_ptr)
        mlx_destroy_image(game->mlx_ptr, game->colection.img_ptr);
    if (game->player_win.img_ptr)
        mlx_destroy_image(game->mlx_ptr, game->player_win.img_ptr);
}
