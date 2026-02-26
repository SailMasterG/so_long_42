/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:14:59 by chguerre          #+#    #+#             */
/*   Updated: 2026/02/26 20:45:27 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include "solong.h"


void sanitize_line(char *str)
{
    int i;
    i= 0;
    while(str[i] != '\0')
    {
        if(str[i] == '\n')
            str[i] = '\0';
        i++;
    }
}

void free_matrix(char **m)
{
    int i;
    i = 0;
    while(m[i] != NULL)
        free(m[i++]);
    free(m);
 }
int counter_files(char *name)
{
    int fd;
    int count;
    char *line;

    fd = open(name, O_RDONLY);
    if(fd == -1)
        return (0);
    
    line = get_next_line(fd);
    count = 0;
    while (line != NULL)
    {
        free(line);
        line = get_next_line(fd);
        count++;
    }
    close(fd);
    return (count);

}

int create_map_grid(char **m, t_map *map)
{
    int i;
    i = 0;

    map->grid = malloc((map->rows +1)* sizeof(char *));
    if(!map->grid)
    {
        free_matrix(m);
        return (0);
    }
    while(m[i] != NULL)
    {
        map->grid[i] = ft_strdup(m[i]);
        if(!map->grid[i])
        {
            free_matrix(map->grid);
            free_matrix(m);
            return (0);
        }
        i++;
    }
    map->grid[i] = NULL;
    return (1);
}

int map_reader (char *name, t_map *map)
{
    int fd;
    int i = 0;
    char **matriz;
    
    map->rows = counter_files(name);
    matriz = malloc((map->rows + 1) * sizeof(char *));
    if(!matriz)
        return (0);
    fd = open(name,  O_RDONLY);
    if(fd == -1)
    {
        free_matrix(matriz);
        return (0);
    }
    while(i < map->rows )
    {
        matriz[i] = get_next_line(fd);
        if(!matriz)
        {
            free_matrix(matriz);
            close(fd);
            return (0);
        }
        sanitize_line(matriz[i]);
        i++;
    }
    matriz[i] = NULL;
    if(map_validator(matriz, map))
    {
        create_map_grid(matriz, map);
        free_matrix(matriz);
    }
    else
    {
        free_matrix(matriz);
        return (0);
    }
    
    return (1);
}


