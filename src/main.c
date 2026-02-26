/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:11:26 by chguerre          #+#    #+#             */
/*   Updated: 2026/02/26 20:45:44 by chguerre         ###   ########.fr       */
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
    
    return (0);
}