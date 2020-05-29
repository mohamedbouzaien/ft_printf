/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_flag_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 04:23:55 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/05/29 15:54:22 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		capture_int_str(const char *str, int *pos, size_t *enablepart)
{
	int 	i;
	int 	num;
	char	*numinstr;

	i = 0;
	num = 0;
	if (str[*pos] == '-')
		i++;
	if (ft_isdigit(str[*pos + i]))
	{
		*enablepart = 1;
		while (ft_isdigit(str[*pos + i]))
			i++;
		numinstr = ft_substr(str, *pos, i);
		num = atoi(numinstr);
		free(numinstr);
		*pos += i;
	}
	return (num);
}

int		fill_int_star(size_t *enablepart, va_list *ap, int *pos)
{
	int		n;

	n = va_arg(*ap, int);
	*enablepart = 1;
	(*pos)++;
	return (n);
}

void	handle_precision(const char *str, int *pos, va_list *ap, t_flag *flag)
{
	(*pos)++;
	if (str[*pos] == '*')
		flag->precision = fill_int_star(&(flag->precisionenabled), ap, pos);
	else
	{
		flag->precision = capture_int_str(str, pos, &(flag->precisionenabled));
		if (flag->precisionenabled == 0)
			flag->precisionenabled = 1;
	}
}

t_flag	fill_flag_data(const char *str, int *pos, va_list *ap)
{
	t_flag		new;
	const char	*params = "-0";

	
	init_t_flag(&new);
	while (str[(*pos)++] && ft_strchr(params, str[*pos]))
	{
		if (str[*pos] == '-')
			new.justify = 1;
		else if (str[*pos] == '0' && new.justify != 1)
			new.zeroenabled = 1;
		else
		{
			(*pos)++;
			break;
		}
	}
	if (str[*pos] == '*')
	{
		new.width = fill_int_star(&(new.widthenabled), ap, pos);
		if (new.width < 0 && new.justify == 0)
			new.justify = 1;
	}
	else
		new.width = capture_int_str(str, pos, &(new.widthenabled));
	if (str[*pos] == '.')
		handle_precision(str, pos, ap, &new);
	if (ft_isalpha(str[*pos]) || str[*pos] == '%')
		new.type = str[*pos];
	else
		new.type = 0;
	return (new);
}
