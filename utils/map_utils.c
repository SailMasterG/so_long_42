/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:15:31 by sail91            #+#    #+#             */
/*   Updated: 2026/03/02 22:22:01 by chguerre         ###   ########.fr       */
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
        if(!m[i])
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
    matriz = ft_calloc(rows + 1, sizeof(char *));
    if(!matriz)
        return (NULL);
    return (matriz);
}
int  validate_accessibility(char **matrix, t_game *game)
{
    char **copia;
    int c_token;
    int y;
    int x;

    y =game->p_y;
    x =game-> p_x;
    c_token = 0;
    copia = copy_matrix(matrix, game->map.rows);

    
    if(!copia)
    { // Si copy_matrix falló, 'copia' es NULL, no hay nada que liberar.
        return (0);
    }
    flood_fill(copia, game, y, x, &c_token);
    // printf("matrix[0]: %s\n", copia[3]); // Eliminar printf de depuración
    free_matrix(copia);
    if (c_token != game->map.coins + game->map.exit)
        return (0);
    return (1); 
}

char **copy_matrix(char **matrix, int rows)
{
    int i;
    char **dest;
    dest = matrix_allocate(rows);
    i = 0;
    while (i < rows)
    {
        dest[i]=ft_strdup(matrix[i]);
        if (!dest[i])
        {
            free_matrix(dest);
            return (NULL); // Devolver NULL para char**
        }
        i++;
    }
    dest[i] = NULL;
    return (dest); 
}

void flood_fill(char **copy, t_game *game, int y, int x, int *c_token)
{
   // printf("y: %d, x: %d, c_token: %d\n", y, x, *c_token); // Eliminar printf de depuración
    if(y < 0 || y >= game->map.rows || x < 0 || x >= game->map.cols)
        return;
    // printf("copy[y][x]: %c\n", copy[y][x]); // Eliminar printf de depuración
    if(copy[y][x] == '1')
        return;

    if (copy[y][x] == 'V')
        return;
  
    if(copy[y][x] == 'E' || copy[y][x] == 'C' )
        (*c_token)++;
    copy[y][x] = 'V';
    flood_fill(copy,game, y - 1, x, c_token);
    flood_fill(copy,game, y + 1, x, c_token);
    flood_fill(copy,game, y, x - 1, c_token);
    flood_fill(copy,game, y, x + 1, c_token); 
}