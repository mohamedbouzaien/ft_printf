/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 00:03:44 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/01/09 00:37:20 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_chrloc(char *str, int ch)
{
	size_t		length;

	length = 0;
	if (str)
	{
		while (str[length] != ch && str[length] != '\0')
			length++;
	}
	return (length);
}
