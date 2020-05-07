/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 02:47:24 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/05/03 03:43:30 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		udigit_count(uintmax_t n, unsigned int base)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		i++;
		n /= base;
	}
	return (i);
}

char   				*ft_uitoa(uintmax_t n, unsigned int base)
{
	char	*str;
	char	dig[16];
	size_t	i;

	ft_strcpy(dig,"0123456789abcdef");
	i = udigit_count(n, base);
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (i > 0)
	{
		str[i - 1] = dig[n % base];
		i--;
		n /= base;
	}
	return(str);
	
}