/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_va_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 02:21:06 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/05/30 21:54:47 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*format_width_str(t_flag flag, int len, char *str)
{
	char	*added;
	char	*pointerclean;

	added = ft_strnew(flag.width - len);
	ft_memset(added, flag.zeroenabled ? '0' : ' ', flag.width - len);
	pointerclean = str;
	if (flag.justify == 0)
		str = ft_strnjoin(added, str, len);
	else
		str = ft_strnjoin(str, added, flag.width - len);
	free(pointerclean);
	free(added);
	return (str);
}

int		print_va_str(va_list *ap, t_flag flag)
{
	int		len;
	char	*str;
	char	*arg;
	char	*pointerclean;

	arg = va_arg(*ap, char *);
	if (arg == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(arg);
	if (flag.precisionenabled && flag.precision >= 0)
	{
		pointerclean = str;
		str = ft_substr(str, 0, flag.precision);
		free(pointerclean);
	}
	len = ft_strlen(str);
	if (flag.width < 0)
		flag.width = -flag.width;
	if (flag.widthenabled && flag.width - len > 0)
		str = format_width_str(flag, len, str);
	ft_putstr_fd(str, 1);
	free(str);
	return (flag.width - len > 0 ? flag.width : len);
}
