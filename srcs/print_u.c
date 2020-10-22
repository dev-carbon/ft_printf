/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 17:58:00 by humanfou          #+#    #+#             */
/*   Updated: 2020/09/21 21:27:30 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static uintmax_t	get_number(t_params *p)
{
	uintmax_t	num;

	if (p->type == 'U' || ft_strcmp(p->length, "l") == 0)
		num = (unsigned long)(va_arg(p->args, unsigned long int));
	else if (ft_strcmp(p->length, "hh") == 0)
		num = (unsigned char)(va_arg(p->args, unsigned int));
	else if (ft_strcmp(p->length, "h") == 0)
		num = (unsigned short)(va_arg(p->args, unsigned int));
	else if (ft_strcmp(p->length, "ll") == 0)
		num = (unsigned long long)(va_arg(p->args, unsigned long long int));
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
	num_len = ft_nbrlen(p->unumber);
	p->not_blank += p->precision > num_len ? p->precision - num_len : 0;
	p->gap += p->precision == 0 && p->unumber == 0 ? 1 : 0;
	p->gap += p->number < 0 ? p->width - p->not_blank - num_len - 1 :
		p->width - p->not_blank - num_len;
	p->gap = p->gap < 0 ? 0 : p->gap;
	p->pc += num_len + p->gap + p->not_blank;
	p->pc += p->number < 0 ? 1 : 0;
	p->pc -= p->precision == 0 && p->unumber == 0 ? 1 : 0;
}

static void			print_number(t_params *p)
{
	if (p->precision == 0)
	{
		if (p->unumber != 0)
			ft_putnbrumax_fd(p->unumber, 1);
	}
	else
		ft_putnbrumax_fd(p->unumber, 1);
}

void				print_u(t_params *p)
{
	set_params(p);
	if (p->width == 0 && p->precision == 0 && p->unumber == 0)
		return ;
	if (p->flag[0] == '-')
	{
		print_not_blank(p);
		print_number(p);
		print_padding(' ', p->gap);
	}
	else if (p->flag[1] == '0')
	{
		(p->precision > -1) ? print_padding(' ', p->gap) :
			print_padding('0', p->gap);
		print_padding('0', p->not_blank);
		print_number(p);
	}
	else
	{
		print_padding(' ', p->gap);
		print_not_blank(p);
		print_number(p);
	}
}
