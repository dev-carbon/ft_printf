/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:42:30 by humanfou          #+#    #+#             */
/*   Updated: 2020/09/23 17:54:28 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*generate_string(char *str, char *mask, intmax_t value, int base)
{
	uintmax_t	unbr;
	int			i;

	unbr = (value < 0) ? -value : value;
	i = -1;
	if (unbr == 0)
	{
		str[++i] = mask[0];
	}
	else
	{
		while (unbr > 0)
		{
			str[++i] = mask[unbr % base];
			unbr /= base;
		}
		if (value < 0 && base == 10)
			str[++i] = '-';
		str[++i] = '\0';
	}
	ft_strrev(str);
	return (str);
}

char	*ft_itoa_base(intmax_t value, int base, char case_type)
{
	char		*res;
	int			number_length;

	number_length = (value < 0) ? ft_nbrlen(value) + 1 : ft_nbrlen(value);
	if (!(res = (char *)malloc(sizeof(char)) + number_length + 1))
		return (NULL);
	if (case_type == 'x')
		generate_string(res, "0123456789abcdef", value, base);
	else if (case_type == 'X')
		generate_string(res, "0123456789ABCDEF", value, base);
	return (res);
}
