/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:39:21 by chguerre          #+#    #+#             */
/*   Updated: 2026/03/04 17:28:56 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_w;
	int		win_h;
	t_img	canvas;
	t_map	map;
	t_img	wall;
	t_img	floor;
	t_img	player;
	t_img	player_win;
	t_img	colection;
	t_img	img_exit;
	char	prev_tile;
	int		p_x;
	int		p_y;
	int		moves;
	int		c_token;
	/* data */
}			t_game;

#endif // STRUCTS_H
