/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_va_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 02:23:18 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/05/12 18:14:31 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_with_width(t_flag flag, char c)
{
	char	*addedspaces;

	addedspaces = ft_strnew(flag.width - 1);
	ft_memset(addedspaces, ' ', flag.width - 1);
	if (flag.justify == 0)
	{
		ft_putstr_fd(addedspaces, 1);
		ft_putchar_fd(c, 1);
	}
	else
	{
		ft_putchar_fd(c, 1);
		ft_putstr_fd(addedspaces, 1);
	}
	return (ft_strlen(addedspaces));
}

int		print_va_char(va_list *ap, t_flag flag)
{
	int		len;
	char	c;

	c = va_arg(*ap, int);
	if (!c)
		c = 0;
	if (flag.width < 0)
		flag.width = -flag.width;
	len = 1;
	if (flag.widthenabled && flag.width - len > 0)
	{
		len += print_with_width(flag, c);
	}
	else
		ft_putchar_fd(c, 1);
	return (len);
}
