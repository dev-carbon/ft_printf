/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 15:30:48 by humanfou          #+#    #+#             */
/*   Updated: 2020/09/21 15:30:56 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static uintmax_t	get_number(t_params *p)
{
	uintmax_t	number;

	number = (unsigned long)(va_arg(p->args, unsigned long int));
	number = (uintmax_t)number;
	return (number);
}

static void			set_params(t_params *p)
{
	int			num_len;

	p->unumber = get_number(p);
	p->string = ft_itoa_base(p->unumber, 16, 'x');
	num_len = ft_strlen(p->string);
	if (p->precision && p->precision > num_len)
		p->not_blank += p->precision - num_len;
	if (p->unumber == 0 && p->precision == 0)
		num_len -= 1;
	if (p->width && p->width > (num_len + 2))
		p->gap += p->width - (num_len + 2);
	p->pc += p->gap + p->not_blank + num_len + 2;
}

static void			print_string(t_params *p)
{
	write(1, "0x", 2);
	if (p->unumber != 0 || p->precision != 0)
	{
		print_padding('0', p->not_blank);
		ft_putstr(p->string);
	}
}

void				print_p(t_params *p)
{
	set_params(p);
	if (p->flag[0] == '-')
	{
		print_string(p);
		print_padding(' ', p->gap);
	}
	else
	{
		print_padding(' ', p->gap);
		print_string(p);
	}
	free(p->string);
}
