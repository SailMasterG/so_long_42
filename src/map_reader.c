/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:14:59 by chguerre          #+#    #+#             */
/*   Updated: 2026/02/23 22:19:24 by chguerre         ###   ########.fr       */
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

int map_reader (char *name, t_map *map)
{
    int fd;
    int i = 0;
    char **matriz;
  
    map->rows = counter_files(name);
    matriz = malloc((map->rows + 1) * sizeof(char *));
    if(!matriz)
    {
        return (0);
    }
    fd = open(name,  O_RDONLY);
    if(fd == 0 || fd == -1)
        return (0);
    while(i < map->rows )
    {
        matriz[i] = get_next_line(fd);
        sanitize_line(matriz[i]);
        i++;
    }
    matriz[i] = NULL;
    map_validator(matriz, map);
    return (1);
}