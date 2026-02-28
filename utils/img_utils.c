/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 09:46:18 by chguerre          #+#    #+#             */
/*   Updated: 2026/02/28 22:23:27 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int generate_assets(t_game *game)
{
    load_xpm(game->mlx_ptr, PLAYER_XPM, &game->player);
    load_xpm(game->mlx_ptr, FLOOR_XPM, &game->floor);
    load_xpm(game->mlx_ptr, WALL_XPM, &game->wall);
    load_xpm(game->mlx_ptr, EXIT_XPM, &game->img_exit);
    load_xpm(game->mlx_ptr, COLLECTIBLE, &game->colection);
    load_xpm(game->mlx_ptr, PLAYER_WIN, &game->player_win);
    if(!game->floor.img_ptr || !game->player.img_ptr || !game->wall.img_ptr || !game->img_exit.img_ptr || !game->colection.img_ptr || !game->player_win.img_ptr) 
    {
        printf("Error al cargar las imagenes");
        return (0);
    }
    return (1);
}
void load_xpm(void *mlx_p, char *path, t_img *img)
{
    int w; // Variable local
    int h; // Variable local

    img->img_ptr = mlx_xpm_file_to_image(mlx_p, path, &w, &h);
    if(!img->img_ptr)
        return ;
    if (img->img_ptr)
    {
        img->img_w = w; // Asignamos después de la función
        img->img_h = h;
        img->addr = mlx_get_data_addr(img->img_ptr, &img->bbp, &img->line_len, &img->endian);
    }
}