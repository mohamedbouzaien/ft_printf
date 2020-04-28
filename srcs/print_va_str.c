/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_va_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 02:21:06 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/04/26 04:15:31 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_va_str(va_list *ap, t_flag flag)
{
	int		len;
	char	*src;
	char	*addedspaces;

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
		addedspaces = ft_strnew(flag.width - len);
		ft_memset(addedspaces, ' ', flag.width - len);
		if (flag.justify == 0)
			src = ft_strnjoin(addedspaces, src, len);
		else
			src = ft_strnjoin(src, addedspaces, flag.width - len);
	}
	ft_putstr_fd(src, 1);
	return (ft_strlen(src));
}
