/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <humanfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 12:07:16 by humanfou          #+#    #+#             */
/*   Updated: 2020/05/04 12:08:16 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void		oct_4(wint_t c)
{
	unsigned char put[4];

	put[0] = 240 | (c >> 18);
	put[1] = 128 | ((c >> 12) & 63);
	put[2] = 128 | ((c >> 6) & 63);
	put[3] = 128 | (c & 63);
	write(1, put, 4);
}

static void		oct_3(wint_t c)
{
	unsigned char put[3];

	put[0] = 224 | (c >> 12);
	put[1] = 128 | ((c >> 6) & 63);
	put[2] = 128 | (c & 63);
	write(1, put, 3);
}

static void		oct_2(wint_t c)
{
	unsigned char put[2];
	put[0] = 192 | (c >> 6);
	put[1] = 128 | ((c & 63));
	write(1, put, 2);
}

static void		oct_1(wint_t c)
{
	write(1, &c, 1);
}

void ft_putchar(wint_t c)
{
	if (c < 128)
		oct_1(c);
	else if (c < 2048)
		oct_2(c);
	else if (c < 65536)
		oct_3(c);
	else if (c < 1114112)
		oct_4(c);
}