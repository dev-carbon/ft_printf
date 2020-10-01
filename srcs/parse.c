/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <humanfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 20:47:48 by humanfou          #+#    #+#             */
/*   Updated: 2020/08/17 21:25:53 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	reinit_params(t_params *params)
{
	params->flag[0] = '\0';
	params->flag[1] = '\0';
	params->flag[2] = '\0';
	params->flag[3] = '\0';
	params->flag[4] = '\0';
	params->length[0] = '\0';
	params->length[1] = '\0';
	params->gap = 0;
	params->not_blank = 0;
	params->width = 0;
	params->precision = -1;
	params->number = 0;
	params->unumber = 0;
}

static void	get_specifiers(t_params *params)
{
	params->i++;
	get_flags(params);
	get_width(params);
	get_precision(params);
	get_length(params);
	get_type(params);
}

void		parse(t_params *params)
{
	while (params->f_copy[params->i] != '\0')
	{
		if (params->f_copy[params->i] == '%')
		{
			reinit_params(params);
			get_specifiers(params);
			print(params);
		}
		else
		{
			ft_putchar(params->f_copy[params->i]);
			params->pc++;
		}
		params->i++;
	}
}
