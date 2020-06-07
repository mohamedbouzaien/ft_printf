/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_width_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 19:51:47 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/06/07 19:00:27 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		format_width_char(t_flag flag, const char c)
{
	char	*added;

	added = ft_strnew(flag.width - 1);
	ft_memset(added, (flag.zeroenabled && !flag.justify) ? '0' : ' ', \
			flag.width - 1);
	if (flag.justify == 0)
	{
		ft_putstr_fd(added, 1);
		ft_putchar_fd(c, 1);
	}
	else
	{
		ft_putchar_fd(c, 1);
		ft_putstr_fd(added, 1);
	}
	free(added);
	return (flag.width - 1);
}
