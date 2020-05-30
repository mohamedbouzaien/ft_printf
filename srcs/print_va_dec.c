/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_va_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 02:24:09 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/05/30 21:55:35 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_va_dec(va_list *ap, t_flag flag)
{
	int		n;
	int		len;
	char	*str;

	n = 0;
	n = va_arg(*ap, int);
	str = ft_itoa(n);
	format_precision(&str, flag);
	if (flag.width < 0)
		flag.width = -flag.width;
	len = ft_strlen(str);
	if (flag.widthenabled && flag.width - len > 0)
		len = format_width_dec(flag, &str, len);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
