/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:15:31 by sail91            #+#    #+#             */
/*   Updated: 2026/02/26 22:31:50 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int matrix_filler(int rows, char **m, const char *name)
{
    int i;
    i= 0;
    int fd;
    fd = open(name, O_RDONLY);
    if(fd == -1)
    {
        free_matrix(m);
        return (0);
    }
    while(i < rows)
    {
        m[i] = get_next_line(fd);
        if(!m)
        {
            free_matrix(m);
            close(fd);
            return (0);
        }
        sanitize_line(m[i]);
        i++;
    }
    m[i] = NULL;
    return(1);
}

char **matrix_allocate(int rows)
{
    char **matriz;
    matriz = malloc((rows + 1) * sizeof(char *));
    if(!matriz)
        return (NULL);
    return (matriz);
}