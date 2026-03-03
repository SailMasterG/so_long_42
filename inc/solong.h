/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:54:21 by chguerre          #+#    #+#             */
/*   Updated: 2026/03/03 19:38:45 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

#include "libft.h"
#include "structs.h"
#include <fcntl.h>
#include "mlx.h"
#include <keys.h>

//TILE SIZE
# define TILE_S 64
// TEXTURES

# define WALL_XPM "textures/pared.xpm"
# define FLOOR_XPM "textures/suelo_64.xpm"
# define PLAYER_XPM "textures/pollito_64.xpm"
# define PLAYER_WIN "textures/gallina_64.xpm"
# define EXIT_XPM "textures/salida_64.xpm"
# define COLLECTIBLE "textures/maiz.xpm"

// FUNCTIONS MAPS VALIDATION

int map_reader(char *name, t_map *map, t_game *game);
int create_map_grid(char **m, t_map *map);
int map_validator(char **map_matrix, t_map *map, t_game *game);
int matrix_filler(int rows, char **m, const char *name);
void sanitize_line(char *str);
void free_matrix(char **m);
char **matrix_allocate(int rows);
int counter_files(char *name);
int is_suround_by_mur(char **map_matrix, t_map *map);
int valid_map_char(char **map_matrix, t_map *map, t_game *game);
int is_rectangle(char **matrix, t_map *map);
char **copy_matrix(char **matrix, int rows);
int  validate_accessibility(char **matrix, t_game *game);
void flood_fill(char **copy, t_game *game, int y, int x, int *c_token);

int game_init(t_game *game);

int generate_assets(t_game *game);
int render_map(t_game *game);
void load_xpm(void *mlx_p, char *path, t_img *img);
void put_pixel(t_game *game, int color, int x , int y);
void sprite(t_game *g, t_img sprite, int pos_x, int pos_y);
unsigned int get_pixel(t_img *img, int x, int y);
void contador_moves(t_game *game);

//CLOSE
int close_window(t_game *game);
void free_resources(t_game *game);
void free_sprites(t_game *game);


//KEY_HOOKS_ACTIONS
int handle_key(int keysym, t_game *game);
int move_player(t_game *game,int new_y,int new_x);

#endif //SOLONG_H