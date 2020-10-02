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
	wint_t		c;

	if (ft_strcmp(params->length, "l") == 0)
		c = (unsigned long)va_arg(params->args, unsigned long);
	else if (params->type == 'C')
		c = (wchar_t)va_arg(params->args, wint_t);
	else
		c = (char)va_arg(params->args, int);
	c = (wint_t)c;
	return (c);
}

static void		set_params(t_params *params)
{
	params->character = get_character(params);
	if (params->character < 128)
	{
		params->gap += params->width ? params->width - 1 : 0;
		params->pc += params->gap + 1;
	}
	else if (params->character < 2048)
	{
		params->gap += params->width ? params->width - 2 : 0;
		params->pc += params->gap + 2;
	}
	else if (params->character < 65536)
	{
		params->gap += params->width ? params->width - 3 : 0;
		params->pc += params->gap + 3;
	}
	else if (params->character < 1114112)
	{
		params->gap += params->width ? params->width - 4 : 0;
		params->pc += params->gap + 4;
	}
}

void			print_c(t_params *params)
{
	set_params(params);
	if (params->flag[0] == '0' && params->flag[1] != '-')
		print_padding('0', params->gap);
	else if (params->flag[0] != '-')
		print_padding(' ', params->gap);
	ft_putchar(params->character);
	if (params->flag[0] == '-')
		print_padding(' ', params->gap);
}
