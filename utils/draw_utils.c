/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 10:10:44 by chguerre          #+#    #+#             */
/*   Updated: 2026/02/28 22:16:16 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
/* 
Con esta funcion se puede colocar un pixel en la imagen del canvas,
 se calcula la direccion del pixel a modificar y se le asigna el color deseado. 
 Se verifica que las coordenadas x e y estén dentro de los límites de la ventana
 para evitar errores de acceso a memoria.

*/
void put_pixel(t_game *game, int color, int x , int y)
{
    char *dst;
    if(x < 0 || x >= game->win_w || y < 0 || y >= game->win_h)
        return ;
    dst = game->canvas.addr + (y * game->canvas.line_len + x * (game->canvas.bbp / 8));
    *(unsigned int*)dst = color;
}

unsigned int get_pixel(t_img *img, int x, int y)
{
    char *src;
    src = img->addr + (y * img->line_len + x * (img->bbp / 8));
    return(*(unsigned int*)src);
}

void sprite(t_game *g, t_img sprite, int pos_x, int pos_y)
{
    int x;
    int y;
    unsigned int color;
    if(!sprite.img_ptr)
        return ;
    y = 0;
    while (y < sprite.img_h)
    {
        x= 0;
        while (x < sprite.img_w)
        {
            color =get_pixel(&sprite, x, y);
            if(color != 0xff000000) // Si el color no es transparente
                put_pixel(g, color, pos_x + x, pos_y + y);
            x++;
        }
        y++;
    }
    
}