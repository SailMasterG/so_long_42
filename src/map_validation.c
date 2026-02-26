/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:14:59 by chguerre          #+#    #+#             */
/*   Updated: 2026/02/24 17:11:23 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <stdio.h>

int count_char_row(char *str)
{
    size_t count;
    count = 0;
    while(str[count] != '\n')
        count++;
    return(count);
}

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
        printf("Columna temporal: %d\n", (int)col_temp);
        printf("Columna fila: %d\n", col);
        if(col != (int)col_temp)
            return (0);
        i++;
        map->cols = col_temp;
    }
    return(1);
}

int valid_map_char(char **map_matrix, t_map *map)
{
    int i;
    int y;
    map->players=0;
    map->exit =0;
    map->coins = 0;
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
            y++;
        }
        i++;
    }
    if(map->players != 1 || map->coins < 1 || map->exit != 1)
        printf("Hay un valor invalido en el mapa");
    return(1);
}
int is_suround_by_mur(char **map_matrix, t_map *map)
{
    int i;
    int y;
    i=0;
    while(map_matrix[i] != '\0')
    {
        y=0;
        while(map_matrix[i][y] != '\0')
        {
            if(map_matrix[0][y] != '1' || map_matrix[map->rows - 1][y] != '1')
                printf("")
        }

    }
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
    valid_map_char(map_matrix, map);
    printf ("Es rectangulo---\nNRO FILAS: %d\n NRO COL: %d", map->rows, map->cols);
    return(1);
}