/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_va_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 02:26:44 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/05/09 18:30:06 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*init_str_flag_p(uintmax_t l, char **str, t_flag flag)
{
	char	*hex;

	hex = ft_strnew(3);
	hex[0] = '0';
	hex[1] = 'x';
	if (l == 0 && flag.precisionenabled)
		**str = 0;
	hex = ft_strnjoin(hex, *str, ft_strlen(*str));
	free(*str);
	return (hex);
}

int				print_va_hex(va_list *ap, t_flag flag)
{
	int			len;
	char		*str;
	uintmax_t	l;

	l = va_arg(*ap, long long);
	str = ft_uitoa(l, 16);
	if (flag.type == 'p')
		str = init_str_flag_p(l, &str, flag);
	else
		format_precision_dec(&str, flag);
	if (flag.type == 'X')
		str = ft_strupr(str);
	len = ft_strlen(str);
	if (flag.width < 0)
		flag.width = -flag.width;
	if (flag.widthenabled && flag.width - len > 0)
		format_width_dec(flag, &str, len);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
