/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_va_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 02:24:09 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/04/26 17:21:58 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_va_nbr(va_list *ap, t_flag flag)
{
	int n;

	n = 0;
	flag.widthenabled = 1;
	n = va_arg(*ap, int);
	ft_putnbr_fd(n, 1);
	return (ft_intlen(n));
}
