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
	p->string = p->unumber == 0 ? ft_strdup("(nil)") :
		ft_itoa_base(p->unumber, 16, 'x');
	num_len = p->unumber == 0 ? ft_strlen(p->string) :
		ft_strlen(p->string) + 2;
	if (p->width && p->width > num_len)
		p->gap += p->width - num_len;
	p->pc += p->gap + num_len;
}

static void			print_str(t_params *p)
{
	write(1, "0x", 2);
	ft_putstr(p->string);
}

void				print_p(t_params *p)
{
	set_params(p);
	if (p->flag[0] == '-')
	{
		p->unumber == 0 ? ft_putstr(p->string) : print_str(p);
		print_padding(' ', p->gap);
	}
	else
	{
		print_padding(' ', p->gap);
		p->unumber == 0 ? ft_putstr(p->string) : print_str(p);
	}
	free(p->string);
}
