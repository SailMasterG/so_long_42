#ifndef STRUCTS_H
# define STRUCTS_H




typedef struct s_img
{
    void *img_ptr;
    int img_h;
    int img_w;
    void *addr;
    int bbp;
    int line_len;
    int endian;
} t_img;

typedef struct s_map
{
    char **grid; // Mapa 2D para validar
    int cols;
    int rows;
    int coins; // cuenta cuantas monedas restantes
    int exit; // Si vale 1 esta abierto, 0 si la salida esta cerrada;
    int players; //Valida que solo exista un jugador
} t_map;


typedef struct s_game {
    void *mlx_ptr;
    void *win_ptr;
    int win_w;
    int win_h;
    t_img canvas;
    t_map map;
    t_img wall;
    t_img floor;
    t_img player;
    t_img player_win;
    t_img colection;
    t_img img_exit;
    int p_x;
    int p_y;
    int moves;
    /* data */
} t_game;






#endif //STRUCTS_H