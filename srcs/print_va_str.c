/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_va_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 02:21:06 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/05/30 18:07:47 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_va_str(va_list *ap, t_flag flag)
{
	int		len;
	char	*str;
	char	*added;
	char	*pointerclean;

	str = va_arg(*ap, char *);
	if (str == NULL)
		str = ft_strdup("(null)");
	if (flag.precisionenabled && flag.precision >= 0)
		str = ft_substr(str, 0, flag.precision);
	len = ft_strlen(str);
	if (flag.width < 0)
		flag.width = -flag.width;
	if (flag.widthenabled && flag.width - len > 0)
	{
		added = ft_strnew(flag.width - len);
		ft_memset(added, flag.zeroenabled ? '0' : ' ', flag.width - len);
		if (flag.justify == 0)
		{
			pointerclean = str;
			str = ft_strnjoin(added, str, len);
			free(pointerclean);
		}
		else
			str = ft_strnjoin(str, added, flag.width - len);
		free(added);
	}
	ft_putstr_fd(str, 1);
	//free(str);
	return (flag.width - len > 0 ? flag.width : len);
}
