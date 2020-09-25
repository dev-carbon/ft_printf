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
#include "libft/libft.h"

static uintmax_t	get_number(t_params *params)
{
	uintmax_t	num;

	if (ft_strcmp(params->length, "hh") == 0)
		num = (unsigned char)(va_arg(params->args, unsigned int));
	else if (ft_strcmp(params->length, "h") == 0)
		num = (unsigned short)(va_arg(params->args, unsigned int));
	else if (ft_strcmp(params->length, "ll") == 0)
		num = (unsigned long long)(va_arg(params->args,
			unsigned long long int));
	else if (ft_strcmp(params->length, "l") == 0)
		num = (unsigned long)(va_arg(params->args, unsigned long int));
	else if (ft_strcmp(params->length, "j") == 0)
		num = (uintmax_t)(va_arg(params->args, uintmax_t));
	else if (ft_strcmp(params->length, "z") == 0)
		num = (size_t)(va_arg(params->args, size_t));
	else
		num = (unsigned int)(va_arg(params->args, unsigned int));
	num = (uintmax_t)num;
	return (num);
}

static void			set_params(t_params *params)
{
	int		number_length;

	params->unumber = get_number(params);
	number_length = ft_strlen(ft_itoa_base(params->unumber, 16, params->type));
	if (params->width && params->width > number_length)
		params->gap += params->width - number_length;
	if (params->precision && params->precision > number_length)
		params->not_blank += params->precision - number_length;
	if (params->width > params->precision)
		params->gap -= params->not_blank;
	else
		params->gap = 0;
	if (params->flag[4] == '#' && params->unumber != 0)
	{
		params->gap -= 2;
		params->pc += 2;
	}
	params->pc += params->gap + number_length + params->not_blank;
}

static void			print_preffix(t_params *params)
{
	if (params->flag[4] == '#' && params->unumber != 0)
	{
		if (params->type == 'x')
			write(1, "0x", 2);
		if (params->type == 'X')
			write(1, "0X", 2);
	}
}

void				print_x(t_params *params)
{
	set_params(params);
	if (params->unumber == 0 && params->precision == 0)
		print_padding(' ', params->gap + 1);
	else if (params->flag[0] == '-')
	{
		print_preffix(params);
		print_precision(params);
		ft_putstr(ft_itoa_base(params->unumber, 16, params->type));
		print_padding(' ', params->gap);
	}
	else if (params->flag[1] == '0')
	{
		print_preffix(params);
		print_padding('0', params->gap);
		ft_putstr(ft_itoa_base(params->unumber, 16, params->type));
	}
	else
	{
		print_padding(' ', params->gap);
		print_preffix(params);
		print_precision(params);
		ft_putstr(ft_itoa_base(params->unumber, 16, params->type));
	}
}
