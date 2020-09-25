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

static uintmax_t	get_number(t_params *params)
{
	uintmax_t	number;

	number = (unsigned long)(va_arg(params->args, unsigned long int));
	number = (uintmax_t)number;
	return (number);
}

static void		set_params(t_params *params)
{
	params->unumber = get_number(params);
}

void			print_p(t_params *params)
{
	set_params(params);
	if (params->flag[0] == '-')
	{
		ft_putnbr(params->unumber);
		print_padding(' ', params->gap);
	}
	else if (params->flag[1] == '0')
	{
		print_padding('0', params->gap);
		ft_putnbr(params->unumber);
	}
	else
	{
		print_padding(' ', params->gap);
		ft_putnbr(params->unumber);
	}
}