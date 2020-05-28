/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_va_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 02:21:06 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/05/28 15:58:50 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_va_str(va_list *ap, t_flag flag)
{
	int		len;
	char	*src;
	char	*added;

	src = va_arg(*ap, char *);
	if (src == NULL)
		src = ft_strdup("(null)");
	if (flag.precisionenabled && flag.precision >= 0)
		src = ft_substr(src, 0, flag.precision);
	len = ft_strlen(src);
	if (flag.width < 0)
		flag.width = -flag.width;
	if (flag.widthenabled && flag.width - len > 0)
	{
		added = ft_strnew(flag.width - len);
		ft_memset(added, flag.zeroenabled ? '0' : ' ', flag.width - len);
		if (flag.justify == 0)
			src = ft_strnjoin(added, src, len);
		else
			src = ft_strnjoin(src, added, flag.width - len);
	}
	ft_putstr_fd(src, 1);
	return (ft_strlen(src));
}
