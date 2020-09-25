/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinitialize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <humanfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 15:47:31 by humanfou          #+#    #+#             */
/*   Updated: 2020/08/23 15:47:55 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reinitialize(t_params *params)
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
}
