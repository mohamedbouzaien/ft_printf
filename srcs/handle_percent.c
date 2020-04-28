/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 15:48:54 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/04/26 16:12:22 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		find(char *tab, char element)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == element)
			return (i);
		i++;
	}
	return (-1);
}

void	fill_va_fncts(int (*print_va_fncts[3])(va_list *, t_flag flag))
{
	print_va_fncts[0] = print_va_str;
	print_va_fncts[1] = print_va_char;
	print_va_fncts[2] = print_va_nbr;
}

void	handle_percent(const char *format, int *pos, int *psize, va_list *ap)
{
	int		tmp;
	int		(*print_va_fncts[3])(va_list *, t_flag flag);
	char	*tab;
	t_flag	flag;

	fill_va_fncts(print_va_fncts);
	tab = (char[4]) {'s', 'c', 'd', 0};
	*psize += *pos;
	flag = fill_flag_data(format, pos, ap);
	*psize -= *pos;
	tmp = find(tab, format[*pos]);
	if (tmp != -1)
		*psize += (*print_va_fncts[tmp])(ap, flag) - 2;
}
