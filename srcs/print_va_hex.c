/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_va_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 02:26:44 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/05/05 05:31:33 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	add_precisiona(char **src, t_flag flag)
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

int		print_va_hex(va_list *ap, t_flag flag)
{
	int			len;
    char        *str;
	char		*hex;
	char		*added;
    uintmax_t	l;

	l = va_arg(*ap, long long);
    flag.widthenabled = 1;
	str = ft_uitoa(l,16);
	if (flag.type == 'p')
	{
		hex = ft_strnew(3);
		hex[0] = '0';
		hex[1] = 'x'; 
		if (l == 0 && flag.precisionenabled)
			*str = 0;
		hex = ft_strnjoin(hex, str, ft_strlen(str));
		free(str);
		str = hex;
	}
	else
		add_precisiona(&str,flag);
	if (flag.type == 'X')
		str = ft_strupr(str);
	len = ft_strlen(str);
	if (flag.width < 0)
		flag.width = -flag.width;
	if (flag.widthenabled && flag.width - len > 0)
	{
		if (flag.zeroenabled && flag.justify == 0 && (flag.precision < 0 || !flag.precisionenabled))
		{
			flag.precisionenabled = 1;
			flag.precision = flag.width;
			if (str[0] == '-')
				flag.precision--;
			add_precisiona(&str, flag);
		}
		else
		{
			added = ft_strnew(flag.width - len);
			ft_memset(added, ' ', flag.width - len);
			if (flag.justify == 0)
				str = ft_strnjoin(added, str, len);
			else
				str = ft_strnjoin(str, added, flag.width - len);
		}
	}
	ft_putstr_fd(str, 1);
	return(ft_strlen(str));
}