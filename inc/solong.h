/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:54:21 by chguerre          #+#    #+#             */
/*   Updated: 2026/02/26 17:16:12 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
#define SOLONG_H

#include "libft.h"
#include "structs.h"

int map_reader(char *name, t_map *map);
int map_validator(char **map_matrix, t_map *map);

#endif //SOLONG_H