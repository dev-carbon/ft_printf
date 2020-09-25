/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <humanfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 21:00:45 by humanfou          #+#    #+#             */
/*   Updated: 2020/08/23 15:48:36 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize(t_params *params)
{
	params->f_copy = (char *)params->format;
	params->f_treat = (char *)params->format;
	params->flag_mask = "-+ 0#";
	params->type_mask = "cCsSpdDiuxX";
	params->length_mask = "lhjz";
	params->width = 0;
	params->precision = -1;
	params->i = 0;
	params->gap = 0;
	params->not_blank = 0;
	params->pc = 0;
}
