/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:11:26 by chguerre          #+#    #+#             */
/*   Updated: 2026/03/04 12:39:40 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

static void	game_run(t_game *game)
{
	render_map(game);
	mlx_hook(game->win_ptr, 17, 0, close_window, game);
	mlx_hook(game->win_ptr, 2, 1L << 0, handle_key, game);
	mlx_loop(game->mlx_ptr);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (argc != 2)
	{
		printf("Error: Missing map use: ./so_long maps/map.ber\n");
		return (1);
	}
	if (!map_reader(argv[1], &game.map, &game))
	{
		printf("Error: Invalid map file\n");
		return (1);
	}
	if (!game_init(&game))
	{
		printf("Error: game_init failed\n");
		free_resources(&game);
		return (1);
	}
	game_run(&game);
	free_resources(&game);
	return (0);
}
