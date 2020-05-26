/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 15:43:33 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/05/24 23:36:26 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		i;
	int		j;
	int		handlersize;
	int		lastpos;
	va_list	ap;

	va_start(ap, format);
	i = 0;
	j = 0;
	handlersize = 0;
	while (format[i])
	{
		if (i != 0 && format[i - 1] == '%')
		{
			lastpos = i;
			handlersize = handle_flag(format, &i, &ap);
			if (handlersize == -1)
				return (-1);
			else
				j += handlersize - (i - lastpos) - 2;
		}
		else if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
		}
		i++;
	}
	return (i + j);
}
