/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 22:06:29 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/05/05 05:38:09 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int		main()
{
	int		n1;
	int		n2;
	int 	n;
	char	*dummy_ptr1;

	n = 3;
	dummy_ptr1 = (char *)0x7f93b1402710;
	n1 = ft_printf("Le nombre: %0*.*d, la string: %s, le pointeur: %0-8.5X.\n", -4, -4, -12, "abc", 34);
	n2 = printf("Le nombre: %0*.*d, la string: %s, le pointeur: %0-8.5X.\n", -4, -4, -12, "abc", 34);
	printf("taille ft: %d, taille :%d\n", n1, n2);
	return (0);
}
