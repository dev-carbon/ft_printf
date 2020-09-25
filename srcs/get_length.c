/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <humanfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 18:02:11 by humanfou          #+#    #+#             */
/*   Updated: 2020/08/23 18:02:19 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_length(t_params *params)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (params->length_mask[i] != '\0')
	{
		while (params->length_mask[i] == params->f_treat[params->i])
		{
			params->length[j] = params->f_treat[params->i];
			params->length[j + 1] = '\0';
			params->i++;
			j++;
		}
		i++;
	}
}
