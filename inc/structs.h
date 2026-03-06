/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:39:21 by chguerre          #+#    #+#             */
/*   Updated: 2026/03/06 00:02:28 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_anim_state
{
	WALK,
	IDLE
}	t_anim_state;

typedef enum e_direction
{
	UP = 1,
	RIGHT = 2,
	DOWN = 3,
	LEFT = 4
}	t_direccion;


typedef struct s_move
{
	int			px_x;
	int			px_y;
	int			target_x;
	int			target_y;
	int			is_moving;
	t_direccion	direction;
}	t_move;

typedef struct s_img
{
	void	*img_ptr;
	int		img_h;
	int		img_w;
	void	*addr;
	int		bbp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_animate
{
	int				tick_animation;
	int				frame_current;
	t_anim_state	animate_state;
	t_img			walk[4][4];
	t_img			idle[4];
}					t_animate;

typedef struct s_map
{
	char	**grid;
	int		cols;
	int		rows;
	int		coins;
	int		exit;
	int		players;
}			t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_w;
	int			win_h;
	t_img		canvas;
	t_map		map;
	t_img		wall;
	t_img		floor;
	t_animate	player;
	t_animate	hen;
	t_img		colection;
	t_img		img_exit;
	char		prev_tile;
	int			p_x;
	int			p_y;
	int			moves;
	int			c_token;
	/* data */
}			t_game;

#endif // STRUCTS_H
