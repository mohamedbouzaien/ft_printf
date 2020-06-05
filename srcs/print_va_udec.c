/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_va_udec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 03:04:48 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/06/05 03:25:40 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	intmax_t	get_arg(va_list *ap, t_flag flag)
{
	if (flag.modifier == 0)
		return (va_arg(*ap, unsigned int));
	else if (flag.modifier == 'h')
		return ((unsigned short)va_arg(*ap, int));
	else if (flag.modifier == 'h' + 'h')
		return ((unsigned char)va_arg(*ap, int));
	else if (flag.modifier == 'l')
		return (va_arg(*ap, unsigned long));
	else if (flag.modifier == 'l' + 'l')
		return (va_arg(*ap, unsigned long long));
	else
		return (0);
}

int					print_va_udec(va_list *ap, t_flag flag)
{
	int			len;
	char		*str;
	uintmax_t	arg;

	arg = get_arg(ap, flag);
	str = ft_uitoa(arg, 10);
	format_precision(&str, flag);
	len = ft_strlen(str);
	if (flag.width < 0)
		flag.width = -flag.width;
	if (flag.widthenabled && flag.width - len > 0)
		len = format_width_dec(flag, &str, len);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
