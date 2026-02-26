/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:14:59 by chguerre          #+#    #+#             */
/*   Updated: 2026/02/26 20:33:49 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"


int is_rectangle(char **matrix, t_map *map)
{
    int col;
    int i;
    size_t col_temp;

    i = 0;
    col_temp= 0;
    while (i < map->rows)
    {
        col = 0;
        while(matrix[i][col] != '\0')
            col++; 
        if(i == 0)
            col_temp = col;
        if(col != (int)col_temp)
            return (0);
        i++;
    }
    map->cols = col_temp;
    return(1);
}

int valid_map_char(char **map_matrix, t_map *map)
{
    int i;
    int y;

   i=0;
    while(i < map->rows)
    {
        y=0;
        while(map_matrix[i][y] != '\0')
        {
            if(map_matrix[i][y] == 'P')
                map->players++;
            else if(map_matrix[i][y] == 'C')
                map->coins++;
            else if(map_matrix[i][y] == 'E')
                map->exit++;
            else if(!ft_strchr( "1PCE0", map_matrix[i][y]))
                return(0);
            y++;
        }
        i++;
    }
    if(map->players != 1 || map->coins < 1 || map->exit != 1)
        return (0);
    return(1);
}

int is_suround_by_mur(char **map_matrix, t_map *map)
{
    int i;
    int y;
    i=0;
    while(i < map->rows)
    {
        if(i == 0 || i == (map->rows -1))
        {
            y=0;
            while(map_matrix[i][y] != '\0')
            {
                if(map_matrix[i][y] != '1')
                    return (0);
                y++;
            }
        }
        else 
            if (map_matrix[i][0] != '1' || map_matrix[i][map->cols - 1] != '1')
                return (0);
        i++;
    }
    return (1);
}
int map_validator(char **map_matrix, t_map *map)
{
    if(!map_matrix)
        return (0);
    if(!is_rectangle(map_matrix, map))
    {
        printf("NO es un RECTANGULO");
        return (0);
    }
    map->players=0;
    map->exit =0;
    map->coins = 0;
    if(!valid_map_char(map_matrix, map))
    {
        printf("Mapa invalido, hay un elemento que no debe estar");
        return (0);
    }
    if(!is_suround_by_mur(map_matrix, map))
    {
        printf("Error no esta rodeado completamente por un muro");
        return (0);
    }
    return(1);
}