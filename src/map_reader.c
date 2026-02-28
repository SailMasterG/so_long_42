/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:14:59 by chguerre          #+#    #+#             */
/*   Updated: 2026/02/27 19:23:33 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
        return (0);
    while(m[i] != NULL)
    {
        map->grid[i] = ft_strdup(m[i]);
        if(!map->grid[i])
        {
            free_matrix(map->grid);
            return (0);
        }
        i++;
    }
    map->grid[i] = NULL;
    return (1);
}

int map_reader (char *name, t_map *map)
{
    char **matriz;
    map->rows = counter_files(name);
    if(map->rows == 0)
        return (0);
    matriz = matrix_allocate(map->rows);
    if(!matriz)
    {
        printf("Error al asignar memoria para la matriz\n");
        return (0);
    }
    if(!matrix_filler(map->rows,matriz, name))
    {
        free_matrix(matriz);
        return (0);
    }
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


