/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 17:22:08 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/05/29 16:05:16 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	void	format_zeroes(t_flag flag, char **str, char **buffer, int len)
{
	char	*addedzeros;
	char	*pointerclean;

	addedzeros = ft_strnew(flag.precision - len);
	ft_memset(addedzeros, '0', flag.precision - len);
	if (*buffer)
	{
		pointerclean = *buffer;
		*buffer = ft_strnjoin(*buffer, addedzeros, flag.precision - len);
		free(pointerclean);
		pointerclean = *str;
		*str = ft_strnjoin(*buffer, *str, len);
		free(pointerclean);
		free(*buffer);
	}
	else
	{
		pointerclean = *str;
		*str = ft_strnjoin(addedzeros, *str, len);
		free(pointerclean);
	}
	free(addedzeros);
}

void			format_precision(char **str, t_flag flag)
{
	int		len;
	char	*added;
	char	*pointerclean;

	added = NULL;
	if (*str[0] == '-')
	{
		added = ft_strnew(1);
		pointerclean = *str;
		*str = ft_substr(*str, 1, ft_strlen(*str) - 1);
		free(pointerclean);
		added[0] = '-';
	}
	len = ft_strlen(*str);
	if (flag.precisionenabled && flag.precision > len)
		format_zeroes(flag, str, &added, len);
	else if (flag.precisionenabled && flag.precision == 0 && *str[0] == '0')
		*str[0] = 0;
	else if (added)
	{
		pointerclean = *str;
		*str = ft_strnjoin(added, *str, len);
		free(pointerclean);
		free(added);
	}
}
