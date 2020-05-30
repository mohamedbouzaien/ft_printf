/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_va_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 02:26:44 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/05/30 17:22:58 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*init_str_flag_p(char **str)
{
	char	*hex;
	char	*pointerclean;

	hex = ft_strdup("0x");
	pointerclean = hex;
	hex = ft_strnjoin(hex, *str, ft_strlen(*str));
	free(pointerclean);
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
	format_precision(&str, flag);
	if (flag.type == 'p')
		str = init_str_flag_p(&str);
	if (flag.type == 'X')
		str = ft_strupr(str);
	len = ft_strlen(str);
	if (flag.width < 0)
		flag.width = -flag.width;
	if (flag.widthenabled && flag.width - len > 0)
		len = format_width_dec(flag, &str, len);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
