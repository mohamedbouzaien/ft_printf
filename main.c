/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 22:06:29 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/05/30 20:27:41 by mbouzaie         ###   ########.fr       */
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
	n2 = printf("%10.3s", "hi low");
	printf("|\n");
	n1 = ft_printf("%10.3s", "hi low");
	printf("|\n");
	printf("taille ft: %d, taille :%d\n", n1, n2);
	return (0);
}
