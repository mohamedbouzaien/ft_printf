/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_va_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 02:24:09 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/06/02 15:17:04 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_va_dec(va_list *ap, t_flag flag)
{
	int		n;
	int		len;
	char	*str;
	char	*clearpointer;

	n = 0;
	n = va_arg(*ap, int);
	str = ft_itoa(n);
	if ((flag.signenabled || flag.spaceenabled) && n >= 0)
	{
		clearpointer = str;
		if (flag.signenabled && n >= 0)
			str = ft_strjoin("+", str);
		if (flag.spaceenabled && n >= 0)
			str = ft_strjoin(" ", str);
		free(clearpointer);
	}
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
