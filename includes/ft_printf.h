/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 16:30:39 by mbouzaie          #+#    #+#             */
/*   Updated: 2020/05/09 17:40:49 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef	struct		s_flag
{
	int				justify;
	char			type;
	int				width;
	int				precision;
	size_t			zeroenabled;
	size_t			widthenabled;
	size_t			precisionenabled;
}					t_flag;

int					ft_printf(const char *format, ...);
int					print_va_char(va_list *ap, t_flag flag);
int					print_va_nbr(va_list *ap, t_flag flag);
int					print_va_str(va_list *ap, t_flag flag);
int					print_va_hex(va_list *ap, t_flag flag);
void				handle_percent(const char *format, int *pos, int *psize, \
									va_list *ap);
void				init_t_flag(t_flag *flag);
void				format_precision_dec(char **str, t_flag flag);
void				format_width_dec(t_flag flag, char **str, int len);
t_flag				fill_flag_data(const char *str, int *pos, va_list *ap);
#endif
