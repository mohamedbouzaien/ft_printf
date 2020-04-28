/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 22:30:39 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/01/09 00:32:43 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*temp;

	temp = lst;
	size = 0;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}
