/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <humanfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 21:45:31 by humanfou          #+#    #+#             */
/*   Updated: 2020/08/17 21:46:05 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_flags(t_params *params)
{
	int	i;

	i = -1;
	while (params->flag_mask[++i] != '\0')
	{
		while (params->flag_mask[i] == params->f_treat[params->i])
		{
			while (params->f_treat[params->i] == '-' && params->i++)
				params->flag[0] = '-';
			while (params->f_treat[params->i] == '0' && params->i++)
				params->flag[1] = '0';
			while (params->f_treat[params->i] == '+' && params->i++)
				params->flag[2] = '+';
			while (params->f_treat[params->i] == ' ' && params->i++)
				params->flag[3] = ' ';
			while (params->f_treat[params->i] == '#' && params->i++)
				params->flag[4] = '#';
			i = 0;
		}
	}
}
