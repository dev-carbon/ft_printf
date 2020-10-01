/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <humanfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 21:44:27 by humanfou          #+#    #+#             */
/*   Updated: 2020/08/17 21:46:40 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_precision(t_params *params)
{
	while (params->f_treat[params->i] == '.' && params->i++)
		params->precision = 0;
	if (params->f_treat[params->i] == '*' && params->i++)
		params->precision = va_arg(params->args, int);
	else
	{
		while (params->f_treat[params->i] >= '0' &&
			params->f_treat[params->i] <= '9')
		{
			params->precision *= 10;
			params->precision += (params->f_treat[params->i] - '0');
			params->i++;
		}
	}
}
