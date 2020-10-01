/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <humanfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 09:30:02 by humanfou          #+#    #+#             */
/*   Updated: 2020/08/06 09:30:12 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_params(t_params *params)
{
	params->f_copy = (char *)params->format;
	params->f_treat = (char *)params->format;
	params->flag_mask = "-+ 0#";
	params->type_mask = "cCsSpdDiuxX%";
	params->length_mask = "lhjz";
	params->width = 0;
	params->precision = -1;
	params->i = 0;
	params->gap = 0;
	params->not_blank = 0;
	params->pc = 0;
	params->number = 0;
	params->unumber = 0;
}

int			ft_printf(const char *format, ...)
{
	t_params	*params;

	if (!(params = (t_params *)malloc(sizeof(t_params))))
		return (-1);
	params->format = format;
	init_params(params);
	if (format)
	{
		va_start(params->args, format);
		parse(params);
		va_end(params->args);
	}
	free(params);
	return (params->pc);
}
