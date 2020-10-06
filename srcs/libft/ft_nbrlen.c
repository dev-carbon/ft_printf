/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 15:50:18 by humanfou          #+#    #+#             */
/*   Updated: 2020/09/23 15:53:17 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen(intmax_t number)
{
	size_t		len;
	uintmax_t	unumber;

	len = 1;
	len += number < 0 ? 1 : 0;
	unumber = (number < 0) ? -number : number;
	while ((unumber /= 10) > 0)
		len++;
	return (len);
}
