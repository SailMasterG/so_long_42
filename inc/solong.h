/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:54:21 by chguerre          #+#    #+#             */
/*   Updated: 2026/02/28 22:11:40 by chguerre         ###   ########.fr       */
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
void load_xpm(void *mlx_p, char *path, t_img *img);
void put_pixel(t_game *game, int color, int x , int y);
void sprite(t_game *g, t_img sprite, int pos_x, int pos_y);
unsigned int get_pixel(t_img *img, int x, int y);

//CLOSE
int close_window(t_game *game);
void free_resources(t_game *game);
void free_sprites(t_game *game);

#endif //SOLONG_H