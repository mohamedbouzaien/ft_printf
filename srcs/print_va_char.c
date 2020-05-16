/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_va_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 02:23:18 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/05/16 19:54:44 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_va_char(va_list *ap, t_flag flag)
{
	int		len;
	char	c;

	c = va_arg(*ap, int);
	if (!c)
		c = 0;
	if (flag.width < 0)
		flag.width = -flag.width;
	len = 1;
	if (flag.widthenabled && flag.width - len > 0)
	{
		len += format_width_char(flag, c);
	}
	else
		ft_putchar_fd(c, 1);
	return (len);
}
