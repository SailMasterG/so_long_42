/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:11:26 by chguerre          #+#    #+#             */
/*   Updated: 2026/02/26 22:43:10 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mlx.h"
#include "solong.h"

int main(int argc , char *argv[])
{
    t_map mapa1;
    
    if(argc != 2)
        return (1);
    map_reader(argv[1], &mapa1 );
    free_matrix(mapa1.grid);
    return (0);
}