/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 16:03:21 by humanfou          #+#    #+#             */
/*   Updated: 2020/09/23 16:03:27 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintmax_t	get_number(t_params *p)
{
	uintmax_t	num;

	if (ft_strcmp(p->length, "hh") == 0)
		num = (unsigned char)(va_arg(p->args, unsigned int));
	else if (ft_strcmp(p->length, "h") == 0)
		num = (unsigned short)(va_arg(p->args, unsigned int));
	else if (ft_strcmp(p->length, "ll") == 0)
		num = (unsigned long long)(va_arg(p->args,
			unsigned long long int));
	else if (ft_strcmp(p->length, "l") == 0)
		num = (unsigned long)(va_arg(p->args, unsigned long int));
	else if (ft_strcmp(p->length, "j") == 0)
		num = (uintmax_t)(va_arg(p->args, uintmax_t));
	else if (ft_strcmp(p->length, "z") == 0)
		num = (size_t)(va_arg(p->args, size_t));
	else
		num = (unsigned int)(va_arg(p->args, unsigned int));
	num = (uintmax_t)num;
	return (num);
}

static void			set_params(t_params *p)
{
	int			num_len;

	p->unumber = get_number(p);
	p->string = ft_itoa_base(p->unumber, 16, p->type);
	num_len = ft_strlen(p->string);
	p->not_blank += p->precision > num_len ?
		p->precision - num_len : 0;
	p->gap += p->precision == 0 && p->unumber == 0 ? 1 : 0;
	p->gap += p->number < 0 ?
		p->width - p->not_blank - num_len - 1 :
		p->width - p->not_blank - num_len;
	if (p->flag[4] == '#' && p->unumber != 0)
	{
		p->gap -= 2;
		p->pc += 2;
	}
	p->gap = p->gap < 0 ? 0 : p->gap;
	p->pc += num_len + p->gap + p->not_blank;
	p->pc -= p->precision == 0 && p->unumber == 0 ? 1 : 0;
}

static void			print_preffix(t_params *p)
{
	if (p->flag[4] == '#' && p->unumber != 0)
	{
		if (p->type == 'x')
			write(1, "0x", 2);
		if (p->type == 'X')
			write(1, "0X", 2);
	}
}

static void			handle_flag_zero_precison(t_params *p)
{
	if (p->precision > -1)
	{
		print_padding(' ', p->gap);
		print_preffix(p);
	}
	else
	{
		print_preffix(p);
		print_padding('0', p->gap);
	}
}

void				print_x(t_params *p)
{
	set_params(p);
	if (p->unumber == 0 && p->precision == 0)
		print_padding(' ', p->gap);
	else if (p->flag[0] == '-')
	{
		print_preffix(p);
		print_not_blank(p);
		ft_putstr(p->string);
		print_padding(' ', p->gap);
	}
	else if (p->flag[1] == '0')
	{
		handle_flag_zero_precison(p);
		print_padding('0', p->not_blank);
		ft_putstr(p->string);
	}
	else
	{
		print_padding(' ', p->gap);
		print_preffix(p);
		print_not_blank(p);
		ft_putstr(p->string);
	}
	free(p->string);
}
