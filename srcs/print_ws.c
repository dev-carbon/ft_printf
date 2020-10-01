/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ws.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 04:46:11 by humanfou          #+#    #+#             */
/*   Updated: 2020/09/28 04:46:16 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static wchar_t	*get_string(t_params *params)
{
	wchar_t	*string;

	string = (wchar_t *)va_arg(params->args, wchar_t *);
	return (string);
}

static void		set_params(t_params *params)
{
	params->wstring = get_string(params);
}

static wchar_t	*wstrndup(wchar_t *s1, size_t n)
{
	wchar_t	*s2;
	size_t	i;

	i = 0;
	if (!(s2 = (wchar_t *)malloc(sizeof(wchar_t) * n + 1)))
		exit(-1);
	while (s1[i] && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

static wchar_t	*wstrdup(wchar_t *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (wstrndup(str, len));
}

void			do_null(t_params *params)
{
	wchar_t		*s;
	int			i;

	i = 0;
	s = wstrdup(L"(null)");
	if (params->precision > -1)
	{
		while (s[i] && params->precision-- > 0)
			print_wchar(params);
	}
	else
	{
		while (s[i])
			print_wchar(params);
	}
	free(s);
}

void			print_ws(t_params *params)
{
	int		len;
	int		i;

	i = -1;
	set_params(params);
	while (params->string[++i])
		len += ft_charlen(params->string[i]);
}
