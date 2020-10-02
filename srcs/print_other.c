/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 16:00:23 by humanfou          #+#    #+#             */
/*   Updated: 2020/09/27 16:00:27 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	set_params(t_params *params)
{
	if (params->type == '%')
		params->pc++;
}

void		print_other(t_params *params)
{
	set_params(params);
	if (params->type == '%')
		ft_putchar(params->type);
}
