/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 22:06:29 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/04/27 02:53:10 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int		main()
{
	int	n1;
	int	n2;

	n1 = ft_printf("Le nombre: %d, la string: %s, le char: %c\n", 10, "abc", 'k');
	n2 = printf("Le nombre: %d, la string: %s, le char: %c\n", 10, "abc", 'k');
	printf("taille ft: %d, taille :%d\n", n1, n2);
	return (0);
}
