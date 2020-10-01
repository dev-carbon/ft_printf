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
#include "libft.h"

static uintmax_t	get_number(t_params *params)
{
	uintmax_t	number;

	number = (unsigned long)(va_arg(params->args, unsigned long int));
	number = (uintmax_t)number;
	return (number);
}

static void			set_params(t_params *params)
{
	int			num_len;

	params->unumber = get_number(params);
	params->string = params->unumber == 0 ? ft_strdup("(nil)") :
		ft_itoa_base(params->unumber, 16, 'x');
	num_len = params->unumber == 0 ? ft_strlen(params->string) :
		ft_strlen(params->string) + 2;
	if (params->width && params->width > num_len)
		params->gap += params->width - num_len;
	params->pc += params->gap + num_len;
}

static void			print_str(t_params *params)
{
	write(1, "0x", 2);
	ft_putstr(params->string);
}

void				print_p(t_params *params)
{
	set_params(params);
	if (params->unumber == 0)
		ft_putstr(params->string);
	else if (params->flag[0] == '-')
	{
		print_str(params);
		print_padding(' ', params->gap);
	}
	else
	{
		print_padding(' ', params->gap);
		print_str(params);
	}
	free(params->string);
}
