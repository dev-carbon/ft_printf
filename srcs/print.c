/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <humanfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 20:56:32 by humanfou          #+#    #+#             */
/*   Updated: 2020/08/23 20:56:37 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	print(t_params *p)
{
	if (p->type == 'c' || p->type == 'C')
		print_c(p);
	else if (p->type == 'd' || p->type == 'i' || p->type == 'D')
		print_d(p);
	else if (p->type == 's' && ft_strcmp(p->length, "l") == 0)
		print_s(p);
	else if (p->type == 'o')
		print_o(p);
	else if (p->type == 's')
		print_s(p);
	else if (p->type == 'p')
		print_p(p);
	else if (p->type == 'u' || p->type == 'U')
		print_u(p);
	else if (p->type == 'x' || p->type == 'X')
		print_x(p);
	else if (p->type == '%')
		print_percent(p);
	else
		print_undefined();
}
