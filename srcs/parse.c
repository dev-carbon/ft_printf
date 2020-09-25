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
#include "libft/libft.h"

static void	get_specifier(t_params *params)
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
			reinitialize(params);
			get_specifier(params);
			print(params);
		}
		else
		{
			ft_putchar(params->f_copy[params->i]);
			params->pc += 1;
		}
		params->i++;
	}
}
