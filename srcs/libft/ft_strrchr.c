/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 16:46:53 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/01/09 23:29:57 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s);
	while ((i >= 0) && (s[i] != (char)c))
	{
		i--;
	}
	if (i == -1)
		i = 0;
	if (((char)c == '\0' && s[i] == '\0') || (s[i] == (char)c))
		return ((char *)&s[i]);
	return (NULL);
}
