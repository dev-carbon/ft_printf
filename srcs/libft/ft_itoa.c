/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 18:03:19 by humanfou          #+#    #+#             */
/*   Updated: 2020/09/23 19:57:06 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(intmax_t nbr)
{
	uintmax_t	unbr;
	int			number_length;
	int			i;
	char		*res;

	unbr = (nbr < 0) ? -nbr : nbr;
	number_length = (nbr < 0) ? ft_nbrlen(unbr) + 1 : ft_nbrlen(unbr);
	if (!(res = (char *)malloc(sizeof(char) * (number_length + 1))))
		return (NULL);
	i = -1;
	while (unbr > 0)
	{
		res[++i] = (int)unbr % 10 + '0';
		unbr /= 10;
	}
	if (nbr < 0)
		res[++i] = '-';
	res[++i] = '\0';
	ft_strrev(res);
	return (res);
}
