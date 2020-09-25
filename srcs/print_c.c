/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <humanfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 20:57:33 by humanfou          #+#    #+#             */
/*   Updated: 2020/08/23 20:57:35 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static wint_t	get_character(t_params *params)
{
	wint_t	c;

	if (ft_strcmp(params->length, "l") == 0)
		c = (unsigned long)va_arg(params->args, unsigned long);
	else if (params->type == 'C')
		c = (wchar_t)va_arg(params->args, wint_t);
	else
		c = (char)va_arg(params->args, int);
	c = (wint_t)c;
	return (c);
}

static void set_params(t_params *params)
{
	params->character = get_character(params);
	if (params->width)
		params->gap = params->width - 1;
	params->pc += params->gap + 1;
}

void print_c(t_params *params)
{
	set_params(params);
	if (params->flag[0] == '-')
	{
		ft_putchar(params->character);
		print_padding(' ', params->gap);
	}
	else
	{
		print_padding(' ', params->gap);
		ft_putchar(params->character);
	}
}