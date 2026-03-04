/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 10:10:44 by chguerre          #+#    #+#             */
/*   Updated: 2026/03/04 17:54:05 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

/**
 * @brief Places a pixel on the canvas by calculating
 * its memory address and assigning the color.
 *Verifies coordinates are within window limits
 *to prevent memory access errors.
 *
 */
void	put_pixel(t_game *game, int color, int x, int y)
{
	char	*dst;

	if (x < 0 || x >= game->win_w || y < 0 || y >= game->win_h)
		return ;
	dst = game->canvas.addr + (y * game->canvas.line_len + x * (game->canvas.bbp
				/ 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_pixel(t_img *img, int x, int y)
{
	char	*src;

	src = img->addr + (y * img->line_len + x * (img->bbp / 8));
	return (*(unsigned int *)src);
}

/**
 * @brief if the color of pixel is not transparent put it!
 */
void	sprite(t_game *g, t_img sprite, int pos_x, int pos_y)
{
	int				x;
	int				y;
	unsigned int	color;

	if (!sprite.img_ptr)
		return ;
	y = 0;
	while (y < sprite.img_h)
	{
		x = 0;
		while (x < sprite.img_w)
		{
			color = get_pixel(&sprite, x, y);
			if (color != 0xff000000)
				put_pixel(g, color, pos_x + x, pos_y + y);
			x++;
		}
		y++;
	}
}
