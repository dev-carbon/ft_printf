/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_preffix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:55:53 by humanfou          #+#    #+#             */
/*   Updated: 2020/10/22 11:56:28 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_preffix(t_params *p)
{
	if (p->flag[4] == '#')
	{
		if (p->type == 'x' && p->unumber != 0)
			write(1, "0x", 2);
		if (p->type == 'X' && p->unumber != 0)
			write(1, "0X", 2);
		if (p->type == 'o')
			write(1, "0", 1);
	}
}
