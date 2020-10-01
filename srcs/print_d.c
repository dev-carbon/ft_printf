/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <humanfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 10:02:46 by humanfou          #+#    #+#             */
/*   Updated: 2020/08/23 10:02:49 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static intmax_t	get_number(t_params *p)
{
	intmax_t	num;

	if (p->type == 'D')
		num = (long)(va_arg(p->args, long int));
	else if (ft_strcmp(p->length, "hh") == 0)
		num = (signed char)(va_arg(p->args, int));
	else if (ft_strcmp(p->length, "h") == 0)
		num = (short)(va_arg(p->args, int));
	else if (ft_strcmp(p->length, "ll") == 0)
		num = (long long)(va_arg(p->args, long long int));
	else if (ft_strcmp(p->length, "l") == 0)
		num = (long)(va_arg(p->args, long int));
	else if (ft_strcmp(p->length, "j") == 0)
		num = (intmax_t)(va_arg(p->args, intmax_t));
	else if (ft_strcmp(p->length, "z") == 0)
		num = (size_t)(va_arg(p->args, size_t));
	else
		num = (int)(va_arg(p->args, int));
	num = (intmax_t)num;
	return (num);
}

static void		set_params(t_params *p)
{
	int			num_len;

	p->number = get_number(p);
	p->unumber = (p->number < 0) ? -p->number : p->number;
	num_len = ft_nbrlen(p->unumber);
	if (p->precision > -1 && p->precision > num_len)
		p->not_blank += p->precision - num_len;
	p->gap += (p->width && p->width > num_len) ? (p->width - num_len) : 0;
	p->gap -= (p->width > p->precision) ? p->not_blank : p->gap;
	if (p->flag[2] == '+' || p->flag[3] == ' ')
	{
		p->gap--;
		p->pc++;
	}
	p->gap += (p->unumber == 0 && p->precision == 0) ? 1 : 0;
	p->gap -= p->number < 0 ? 1 : 0;
	p->pc += (p->number < 0) ? 1 : 0;
	p->pc += p->gap + p->not_blank + num_len;
}

static void		handle_flag_zero_precison(t_params *p)
{
	if (p->precision > -1)
	{
		print_padding(' ', p->gap);
		print_sign(p);
	}
	else
	{
		print_sign(p);
		print_padding('0', p->gap);
	}
}

static void		print_number(t_params *p)
{
	if (p->unumber != 0 || p->precision != 0)
		ft_putnbrumax_fd(p->unumber, 1);
}

void			print_d(t_params *p)
{
	set_params(p);
	if (p->width == 0 && p->precision == 0 && p->number == 0)
		return ;
	else if (p->flag[0] == '-')
	{
		print_sign(p);
		print_not_blank(p);
		print_number(p);
		print_padding(' ', p->gap);
	}
	else if (p->flag[1] == '0')
	{
		handle_flag_zero_precison(p);
		print_not_blank(p);
		print_number(p);
	}
	else
	{
		print_padding(' ', p->gap);
		print_sign(p);
		print_not_blank(p);
		print_number(p);
	}
}
