/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 21:12:23 by chguerre          #+#    #+#             */
/*   Updated: 2026/01/19 09:44:29 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	va_start(args, str);
	count = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			if (*(str + 1) != '\0' && ft_strchr("cspdiuxX%", *(str + 1)))
			{
				count += printargs((char **)&str, &args);
				str++;
			}
			else
				return (-1);
			continue ;
		}
		ft_putchar_fd(*str, 1);
		count++;
		str++;
	}
	va_end(args);
	return (count);
}

// int main(	)
// {
// 	char s[] = "Rey David";

// 	printf("\nCantidad de caracteres escritos = %d\n",
// 		ft_printf("Ft_printf:El cafe es %s\n %p el numero minimo: %i", "MARRON",
// 			&s,-2147483648));

// 	ft_printf("\nPrueba numero hexadecimal x : %x", -1500);
// 	ft_printf("\nPrueba numero hexadecimal x : %X\n", -1500);

// 	ft_printf("Hola%u\n",-1);
// 	printf("\nPrintf:puntero adress %p \n", &s);

// 	ft_printf("Mi nombre es %s\n Tengo %d años\n Naci en %s\n Pero ahorita estoy en %s\n", "Lucas" , 6, "Venezuela");

// 	return (0);
// }