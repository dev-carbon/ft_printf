/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <humanfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 08:52:53 by humanfou          #+#    #+#             */
/*   Updated: 2020/08/06 08:53:00 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <wchar.h>

int main(void) {

    int	pc_1;
    int	pc_2;
    int    c;

    c = 'H';
    pc_1 = ft_printf("Hello world! %5c\n", c);
    printf("---------------\n");
    pc_2 = printf("Hello world! %5c\n", c);
    printf("---------------\n");
    printf("ft_printf = %d\tprintf = %d\n", pc_1, pc_2);
    printf("---------------\n");
    return 0;
}
