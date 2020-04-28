/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 16:58:20 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/04/26 17:21:13 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_t_flag(t_flag *flag)
{
	flag->justify = 0;
	flag->width = 0;
	flag->precision = 0;
	flag->widthenabled = 0;
	flag->precisionenabled = 0;
}
