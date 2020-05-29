/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_va_udec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 03:04:48 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/05/29 15:05:31 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				print_va_udec(va_list *ap, t_flag flag)
{
	int			len;
	char		*str;
	uintmax_t	l;

	l = va_arg(*ap, long long);
	str = ft_uitoa(l, 10);
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
