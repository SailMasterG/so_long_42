/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 10:10:44 by chguerre          #+#    #+#             */
/*   Updated: 2026/02/28 10:23:54 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void put_pixel(t_game g, int color, int x , int y)
{
    char *dst;
    dst = g.canvas.addr + (y * g.canvas.line_len + x * (g.canvas.bbp / 8));
    *(unsigned int*)dst = color;
}