/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 09:46:18 by chguerre          #+#    #+#             */
/*   Updated: 2026/02/28 10:11:17 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int generate_assets(t_game *game)
{
    printf("iniciando generacion de imagenes\n");
    game->player = load_xpm(game->mlx_ptr, PLAYER_XPM);
    game->floor = load_xpm(game->mlx_ptr, FLOOR_XPM);
    game->wall = load_xpm(game->mlx_ptr, WALL_XPM);
    game->img_exit = load_xpm(game->mlx_ptr, EXIT_XPM);
    game->colection = load_xpm(game->mlx_ptr, COLLECTIBLE);
    game->player_win = load_xpm(game->mlx_ptr, PLAYER_WIN);
    if(!game->floor.img_ptr )
     // game->player.img_ptr 
     //   || !game->floor.img_ptr 
     //  || !game->wall.img_ptr 
     //   || !game->img_exit.img_ptr 
     //  || !game->colection.img_ptr 
     //  || !game->player_win.img_ptr
    //)
    {
        printf("Error al cargar las imagenes");
        return (0);
    }
    return (1);
}
t_img load_xpm(void *mlx_p, char *path)
{
    t_img img;
    img.img_ptr = mlx_xpm_file_to_image(mlx_p, path, &img.img_w, &img.img_h);
    if (img.img_ptr)
        img.addr = mlx_get_data_addr(img.img_ptr, &img.bbp, &img.line_len, &img.endian);
        
    return (img);
}

