/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:11:26 by chguerre          #+#    #+#             */
/*   Updated: 2026/02/28 22:29:26 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mlx.h"
#include "solong.h"

int main(int argc , char *argv[])
{
    t_game game = {0};

    if(argc != 2)
        return (1);
    map_reader(argv[1],&game.map);
    if (!game_init(&game))
    {
        free_resources(&game);
        return (1);
    }
    render_map(&game);
    mlx_hook(game.win_ptr, 17, 0, close_window, &game);
    mlx_loop(game.mlx_ptr);
    free_resources(&game);
    return (0);
}