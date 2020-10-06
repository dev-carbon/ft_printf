/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_field_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <humanfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 21:45:06 by humanfou          #+#    #+#             */
/*   Updated: 2020/08/17 21:46:23 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_width(t_params *params)
{
	if (params->f_treat[params->i] == '*' && params->i++)
	{
		params->width = va_arg(params->args, int);
		if (params->width < 0)
		{
			params->width *= -1;
			params->flag[0] = '-';
		}
	}
	else
	{
		while (params->f_treat[params->i] >= '0' &&
			params->f_treat[params->i] <= '9')
		{
			params->width *= 10;
			params->width += (params->f_treat[params->i] - '0');
			params->i++;
		}
	}
}
