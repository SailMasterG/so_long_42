/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 19:36:16 by chguerre          #+#    #+#             */
/*   Updated: 2026/03/04 11:54:33 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	contador_moves(t_game *game)
{
	char	*moves_str;

	moves_str = ft_itoa(game->moves);
	if (moves_str == NULL)
	{
		printf("Error converting moves to string\n");
		return ;
	}
	mlx_string_put(game->mlx_ptr, game->win_ptr, 32, 32, 0xFFFFFF, moves_str);
	free(moves_str);
}
