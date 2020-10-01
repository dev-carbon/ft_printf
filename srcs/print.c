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
#include "libft.h"

void	print(t_params *params)
{
	char	type;

	type = params->type;
	if (type == 'c' || type == 'C')
		print_c(params);
	else if (type == 'd' || type == 'i' || type == 'D')
		print_d(params);
	else if (type == 's' && ft_strcmp(params->length, "l") == 0)
		print_ws(params);
	else if (type == 'o')
		print_o(params);
	else if (type == 's')
		print_s(params);
	else if (type == 'p')
		print_p(params);
	else if (type == 'u' || type == 'U')
		print_u(params);
	else if (type == 'x' || type == 'X')
		print_x(params);
	else
		print_other(params);
}
