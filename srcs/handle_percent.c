/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 15:48:54 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/05/24 23:26:42 by mbouzaie         ###   ########.fr       */
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

void	fill_va_fncts(int (*print_va_fncts[9])(va_list *, t_flag flag))
{
	print_va_fncts[0] = print_va_str;
	print_va_fncts[1] = print_va_char;
	print_va_fncts[2] = print_va_nbr;
	print_va_fncts[3] = print_va_hex;
	print_va_fncts[4] = print_va_hex;
	print_va_fncts[5] = print_va_hex;
	print_va_fncts[6] = print_va_udec;
	print_va_fncts[7] = print_va_nbr;
	print_va_fncts[8] = print_va_percent;
}

int		handle_flag(const char *format, int *pos, va_list *ap)
{
	int		tmp;
	int		fsize;
	int		(*print_va_fncts[9])(va_list *, t_flag flag);
	char	*tab;
	t_flag	flag;

	fill_va_fncts(print_va_fncts);
	fsize = 0;
	tab = (char[10]) {'s', 'c', 'd', 'p', 'x', 'X', 'u', 'i', '%', 0};
	fsize += *pos;
	flag = fill_flag_data(format, pos, ap);
	fsize -= *pos;
	tmp = find(tab, format[*pos]);
	if (tmp != -1)
		return ((*print_va_fncts[tmp])(ap, flag));
	else
		return (-1);
	
}
