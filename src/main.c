/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:11:26 by chguerre          #+#    #+#             */
/*   Updated: 2026/03/03 12:17:22 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mlx.h"
#include "solong.h"

int main(int argc , char *argv[])
{
    t_game game = {0};

    if(argc != 2)
        return (1);
   
    if (!map_reader(argv[1],&game.map, &game))
    {
        printf("Error: Invalid map file\n");
        return (1);
    }
    if (!game_init(&game))
    {
        free_resources(&game);
        return (1);
    }
    printf("MAP VALIDATION PASSED\n");
    printf("MOVES: %d\n", game.moves);
    printf("COINS LEFT: %d\n", game.map.coins);
    printf("EXIT STATUS: %d\n", game.map.exit);
    printf("PLAYER POSITION: (%d, %d)\n", game.p_x, game.p_y);
    printf("MAP SIZE: %d cols x %d rows\n", game.map.cols, game.map.rows);
    printf("MAP GRID:\n");
    for (int i = 0; i < game.map.rows; i++)
        printf("%s\n", game.map.grid[i]);
   
    render_map(&game);
    mlx_hook(game.win_ptr, 17, 0, close_window, &game);
    mlx_hook(game.win_ptr, 2, 1L<<0, handle_key, &game);
    mlx_loop(game.mlx_ptr);
    free_resources(&game);
    return (0);
}