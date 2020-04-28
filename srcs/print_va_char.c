/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_va_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 02:23:18 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/04/26 17:22:19 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_va_char(va_list *ap, t_flag flag)
{
	char c;

	flag.widthenabled = 0;
	c = va_arg(*ap, int);
	ft_putchar_fd(c, 1);
	return (1);
}
