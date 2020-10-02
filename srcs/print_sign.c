/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 19:01:54 by humanfou          #+#    #+#             */
/*   Updated: 2020/10/01 19:02:27 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void		print_sign(t_params *p)
{
	if (p->number < 0)
		ft_putchar('-');
	else if (p->flag[2] == '+')
		ft_putchar('+');
	else if (p->flag[3] == ' ')
		ft_putchar(' ');
}
