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

void	print(t_params *params)
{
	char	type;

	type = params->type;
	if (type == 'c' || type == 'C')
		print_c(params);
	if (type == 'd' || type == 'i' || type == 'D')
		print_d(params);
	// else if (*flag == 's' && ft_strcmp(tab->argument_flag, "l") == 0)
	// 	display_ws(tab);
	// else if (*flag == 's')
	// 	display_s(tab);
	// else if (*flag == 'S')
	// 	display_ws(tab);
	else if (type == 'p')
		print_p(params);
	else if (type == 'u' || type == 'U')
		print_u(params);
	else if (type == 'x' || type == 'X')
		print_x(params);
	// else if (*flag == 'o' || *flag == 'O')
	// 	display_o(tab);
	// else
	// 	display_other(tab);
}
