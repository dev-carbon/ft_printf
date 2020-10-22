/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 12:44:35 by humanfou          #+#    #+#             */
/*   Updated: 2020/10/19 12:44:39 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	set_params(t_params *p)
{
	p->gap += p->width ? p->width - 1 : 0;
	p->pc += p->gap + 1;
}

void		print_percent(t_params *p)
{
	set_params(p);
	if (p->flag[0] == '-')
	{
		ft_putchar(p->type);
		print_padding(' ', p->gap);
	}
	else if (p->flag[1] == '0')
	{
		print_padding('0', p->gap);
		ft_putchar(p->type);
	}
	else
	{
		print_padding(' ', p->gap);
		ft_putchar(p->type);
	}
}
