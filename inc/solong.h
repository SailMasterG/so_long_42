/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:54:21 by chguerre          #+#    #+#             */
/*   Updated: 2026/02/28 10:11:05 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

#include "libft.h"
#include "structs.h"
#include <fcntl.h>
#include "mlx.h"

#define TILE_S 64
// TEXTURES

#define WALL_XPM "textures/pared.xpm"
#define FLOOR_XPM "textures/suelo_64.xpm"
#define PLAYER_XPM "textures/pollito_64.xpm"
#define PLAYER_WIN "textures/gallina_64.xpm"
#define EXIT_XPM "textures/salida_64.xpm"
#define COLLECTIBLE "textures/maiz.xpm"

// FUNCTIONS MAPS VALIDATION

int map_reader(char *name, t_map *map);
int create_map_grid(char **m, t_map *map);
int map_validator(char **map_matrix, t_map *map);
int matrix_filler(int rows, char **m, const char *name);
void sanitize_line(char *str);
void free_matrix(char **m);
char **matrix_allocate(int rows);
int counter_files(char *name);
int is_suround_by_mur(char **map_matrix, t_map *map);
int valid_map_char(char **map_matrix, t_map *map);
int is_rectangle(char **matrix, t_map *map);

int game_init(t_game *game);

int generate_assets(t_game *game);
int render_map(t_game *game);
t_img load_xpm(void *mlx_p, char *path);
#endif //SOLONG_H