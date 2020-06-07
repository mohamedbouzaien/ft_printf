/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_va_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 19:31:34 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/06/07 19:06:59 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			print_va_percent(va_list *ap, t_flag flag)
{
	int		len;

	(void)ap;
	if (flag.width < 0)
	{
		flag.width = -flag.width;
		if (flag.justify == 0)
			flag.justify = 1;
	}
	len = 1;
	if (flag.widthenabled && flag.width - len > 0)
		len += format_width_char(flag, '%');
	else
		ft_putchar_fd('%', 1);
	return (len);
}
