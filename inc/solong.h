/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:54:21 by chguerre          #+#    #+#             */
/*   Updated: 2026/02/26 22:25:44 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
#define SOLONG_H

#include "libft.h"
#include "structs.h"
#include <fcntl.h>

int map_reader(char *name, t_map *map);
int map_validator(char **map_matrix, t_map *map);
void free_matrix(char **m);
int matrix_filler(int rows, char **m, const char *name);
void sanitize_line(char *str);
char **matrix_allocate(int rows);
#endif //SOLONG_H