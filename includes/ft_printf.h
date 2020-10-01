/*                                                                            */
/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <humanfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 09:56:18 by humanfou          #+#    #+#             */
/*   Updated: 2020/10/01 19:03:42 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <wchar.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_params
{
	va_list     args;
	const char	*format;
	char		*f_copy;
	char		*f_treat;
	char		flag[5];
	char 		length[3];
	char		type;
	int			width;
	int			precision;
	char		*flag_mask;
	char		*type_mask;
	char 		*length_mask;
    int         i;
    int 		gap;
    int 		not_blank;
	int			pc;
	wint_t		character;
	char		*string;
	wchar_t		*wstring;
	intmax_t	number;
    uintmax_t 	unumber;
}               t_params;

int     	ft_printf(const char *format, ...);
void		parse(t_params *params);
void		print(t_params *params);
void		get_flags(t_params *params);
void		get_width(t_params *params);
void		get_precision(t_params *params);
void		get_length(t_params *params);
void		get_type(t_params *params);
void		print_c(t_params *params);
void		print_s(t_params *params);
void		print_o(t_params *params);
void		print_p(t_params *params);
void		print_d(t_params *params);
void		print_u(t_params *params);
void		print_wchar(t_params *params);
void		print_ws(t_params *params);
void		print_x(t_params *params);
void		print_other(t_params *params);
void		print_sign(t_params *p);
void		print_padding(char padding, int gap);
void		print_not_blank(t_params *params);
void		print_params(t_params *params);

#endif
