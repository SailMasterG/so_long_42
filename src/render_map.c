/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 22:15:29 by chguerre          #+#    #+#             */
/*   Updated: 2026/02/28 10:11:22 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int render_map(t_game *game)
{
    printf("Iniciando imagenes\n");
    if(!generate_assets(game))
    {

        printf("Fallo la generacion\n");
        return(0);
    }
    int x;
    int y;
    y = 0;
    while (y < game->map.rows)
    {
        x = 0;
        while (x < game->map.cols)
        {
            mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor.img_ptr, TILE_S * x,  TILE_S * y);
           if (game->map.grid[y][x]== '1')
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall.img_ptr, TILE_S * x,  TILE_S * y);
           if (game->map.grid[y][x]== 'P')                 
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player.img_ptr, TILE_S * x,  TILE_S * y);
           if (game->map.grid[y][x]== 'C')                 
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->colection.img_ptr, TILE_S * x,  TILE_S * y);
           if (game->map.grid[y][x]== 'E')                 
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_exit.img_ptr, TILE_S * x,  TILE_S * y);
        x++;
        }
     y++;
    }
    return (1);
}