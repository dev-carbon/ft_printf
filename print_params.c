/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <humanfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 21:10:39 by humanfou          #+#    #+#             */
/*   Updated: 2020/08/17 21:11:13 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_params(t_params *params)
{
	int	i;

	i = -1;
	while (++i < 5)
		printf("flag[%d] = %c\n", i, params->flag[i]);
	printf("---------------------------------------\n");
	printf("width = %d\n", params->width);
	printf("---------------------------------------\n");
	printf("length = %s\n", params->length);
	printf("---------------------------------------\n");
	printf("precision = %d\n", params->precision);
	printf("---------------------------------------\n");
	printf("type = %c\n", params->type);
	printf("---------------------------------------\n");
	printf("gap = %d\n", params->gap);
	printf("---------------------------------------\n");
	printf("printed characters = %d\n", params->pc);
	printf("---------------------------------------\n");
	printf("not blank = %d\n", params->not_blank);
	printf("---------------------------------------\n");
	printf("number = %ld\n", params->number);
	printf("---------------------------------------\n");
	printf("unumber = %ld\n", params->unumber);
	printf("---------------------------------------\n");
	printf("string = %s\n", params->string);
}