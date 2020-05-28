/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 15:43:33 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/05/28 14:14:12 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		pos;
	int		flagssize;
	int		handlersize;
	int		lastpos;
	va_list	ap;

	va_start(ap, format);
	pos = 0;
	flagssize = 0;
	handlersize = 0;
	while (format[pos])
	{
		if (format[pos] == '%')
		{
			lastpos = pos;
			handlersize = handle_flag(format, &pos, &ap);
			if (handlersize == -1)
				return (-1);
			else
				flagssize += handlersize - (pos - lastpos) - 1;
		}
		else if (format[pos] != '%')
		{
			ft_putchar_fd(format[pos], 1);
		}
		pos++;
	}
	return (pos + flagssize);
}
