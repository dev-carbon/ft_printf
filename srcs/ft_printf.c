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
#include "libft/libft.h"

int		ft_printf(const char *format, ...)
{
	t_params	*params;

	if (!(params = (t_params *)malloc(sizeof(t_params))))
		return (-1);
	params->format = format;
	initialize(params);
	if (format)
	{
		va_start(params->args, format);
		parse(params);
		va_end(params->args);
	}
	free(params);
	return (params->pc);
}
