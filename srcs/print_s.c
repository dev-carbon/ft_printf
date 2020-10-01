/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 20:19:33 by humanfou          #+#    #+#             */
/*   Updated: 2020/09/27 20:19:35 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*get_string(t_params *params)
{
	char	*string;

	string = (char *)va_arg(params->args, char *);
	return (string);
}

static void	set_params(t_params *params)
{
	int		str_len;

	params->string = get_string(params);
	str_len = ft_strlen(params->string);
	if (params->precision > -1 && params->string)
		params->string = ft_strndup(params->string, params->precision);
	else if (params->precision > -1 && !params->string)
		params->string = (params->precision < 6) ? ft_strnew(0) :
			ft_strndup("(null)", params->precision);
	else if (params->precision == -1 && params->string)
		params->string = ft_strdup(params->string);
	else if (params->precision <= -1 && !params->string)
		params->string = ft_strdup("(null)");
	if (params->width && params->width > (str_len = ft_strlen(params->string)))
		params->gap += params->width - str_len;
	params->pc += params->gap + str_len;
}

void		print_s(t_params *params)
{
	set_params(params);
	if (params->flag[0] != '-')
		print_padding(' ', params->gap);
	ft_putstr_fd(params->string, 1);
	if (params->flag[0] == '-')
		print_padding(' ', params->gap);
	free(params->string);
}
