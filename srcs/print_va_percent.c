/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_va_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 19:31:34 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/05/30 21:49:55 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	int	print_with_zeroes(t_flag flag)
{
	int		len;
	char	*str;

	flag.precisionenabled = 1;
	flag.precision = flag.width;
	str = ft_strdup("%");
	format_precision(&str, flag);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}

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
	{
		if (flag.zeroenabled && flag.justify == 0)
			len = print_with_zeroes(flag);
		else
			len += format_width_char(flag, '%');
	}
	else
		ft_putchar_fd('%', 1);
	return (len);
}
