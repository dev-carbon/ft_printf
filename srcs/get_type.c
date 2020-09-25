/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <humanfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 21:43:00 by humanfou          #+#    #+#             */
/*   Updated: 2020/08/17 21:44:04 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_type(t_params *params)
{
	int		i;

	i = -1;
	while (params->type_mask[++i] != '\0')
		if (params->type_mask[i] == params->f_treat[params->i])
			params->type = params->f_treat[params->i];
}
