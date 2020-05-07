/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_va_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 02:24:09 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/05/03 04:33:08 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
void	add_precision(char **src, t_flag flag)
{
	int		len;
	char	*addedzeros;
	char	*added;

	added = NULL;
	if (*src[0] == '-')
	{
		added = ft_strnew(1);
		*src = ft_substr(*src,1, ft_strlen(*src) - 1);
		added[0] = '-';
	}
	len = ft_strlen(*src);                                                                        
	if (flag.precisionenabled && flag.precision > len)
	{
		addedzeros = ft_strnew(flag.precision - len);
		ft_memset(addedzeros, '0', flag.precision - len);
		if (added)
		{
			added = ft_strnjoin(added, addedzeros, flag.precision - len);
			*src = ft_strnjoin(added, *src, len);
			free(added);
		}
		else
			*src = ft_strnjoin(addedzeros, *src, len);
		free(addedzeros);
	}
	else if (flag.precisionenabled && flag.precision ==  0 && *src[0] == '0')
		*src[0] = 0;
	else if (added)
	{
		*src = ft_strnjoin(added, *src, len);
		free(added);
	}
}
int		print_va_nbr(va_list *ap, t_flag flag)
{
	int 	n;
	int		len;
	char	*src;
	char	*added;

	n = 0;
	n = va_arg(*ap, int);
	src = ft_itoa(n);
	add_precision(&src,flag);
	if (flag.width < 0)
		flag.width = -flag.width;
	len = ft_strlen(src);       
	if (flag.widthenabled && flag.width - len > 0)
	{
		if (flag.zeroenabled && flag.justify == 0 && (flag.precision < 0 || !flag.precisionenabled))
		{
			flag.precisionenabled = 1;
			flag.precision = flag.width;
			if (src[0] == '-')
				flag.precision--;
			add_precision(&src, flag);
		}
		else
		{
			added = ft_strnew(flag.width - len);
			ft_memset(added, ' ', flag.width - len);
			if (flag.justify == 0)
				src = ft_strnjoin(added, src, len);
			else
				src = ft_strnjoin(src, added, flag.width - len);
		}
	}
	ft_putstr_fd(src, 1);
	return (ft_strlen(src));
}
