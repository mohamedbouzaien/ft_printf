/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:46:10 by mbouzaie          #+#    #+#             */
/*   Updated: 2019/11/11 14:46:18 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*p;
	size_t			i;
	unsigned char	mychar;

	mychar = (unsigned char)c;
	p = (char *)b;
	i = 0;
	while (i < len)
	{
		p[i] = mychar;
		i++;
	}
	return (b);
}
