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

static intmax_t	get_number(t_params *params)
{
	intmax_t	num;

	if (params->type == 'D')
		num = (long)(va_arg(params->args, long int));
	else if (ft_strcmp(params->length, "hh") == 0)
		num = (signed char)(va_arg(params->args, int));
	else if (ft_strcmp(params->length, "h") == 0)
		num = (short)(va_arg(params->args, int));
	else if (ft_strcmp(params->length, "ll") == 0)
		num = (long long)(va_arg(params->args, long long int));
	else if (ft_strcmp(params->length, "l") == 0)
		num = (long)(va_arg(params->args, long int));
	else if (ft_strcmp(params->length, "j") == 0)
		num = (intmax_t)(va_arg(params->args, intmax_t));
	else if (ft_strcmp(params->length, "z") == 0)
		num = (size_t)(va_arg(params->args, size_t));
	else
		num = (int)(va_arg(params->args, int));
	num = (intmax_t)num;
	return (num);
}

static void		set_params(t_params *params)
{
	intmax_t	number;

	params->number = get_number(params);
	number = params->number;
	params->unumber = (number < 0) ? -number : number;
	params->gap += params->width - ft_nbrlen(number);
	if (params->flag[2] == '+' || params->flag[3] == ' ' ||
		params->number < 0)
		params->gap -= 1;
}

static void		print_sign(t_params *params)
{
	if (params->number < 0)
		ft_putchar('-');
	else if (params->flag[2] == '+')
		ft_putchar('+');
	else if (params->flag[3] == ' ')
		ft_putchar(' ');
}

void			print_d(t_params *params)
{
	set_params(params);
	if (params->flag[0] == '-')
	{
		print_sign(params);
		ft_putnbr(params->unumber);
		print_padding(' ', params->gap);
	}
	else if (params->flag[1] == '0')
	{
		print_sign(params);
		print_padding('0', params->gap);
		ft_putnbr(params->unumber);
	}
	else
	{
		print_padding(' ', params->gap);
		print_sign(params);
		ft_putnbr(params->unumber);
	}
}
