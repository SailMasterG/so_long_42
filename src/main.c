/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:11:26 by chguerre          #+#    #+#             */
/*   Updated: 2026/02/28 10:00:25 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mlx.h"
#include "solong.h"

int main(int argc , char *argv[])
{
    t_game game;
    
    if(argc != 2)
        return (1);
    map_reader(argv[1],&game.map);
    game_init(&game);
    render_map(&game);
    mlx_loop(game.mlx_ptr);
    free_matrix(game.map.grid);
    return (0);
}