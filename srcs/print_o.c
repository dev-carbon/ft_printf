
#include "ft_printf.h"
#include "libft/libft.h"

static uintmax_t	get_number(t_params *params)
{
	uintmax_t	num;

	if (ft_strcmp(params->length, "hh") == 0)
		num = (unsigned char)(va_arg(params->args, unsigned int));
	else if (ft_strcmp(params->length, "h") == 0)
		num = (unsigned short)(va_arg(params->args, unsigned int));
	else if (ft_strcmp(params->length, "ll") == 0)
		num = (unsigned long long)(va_arg(params->args,
			unsigned long long int));
	else if (ft_strcmp(params->length, "l") == 0)
		num = (unsigned long)(va_arg(params->args, unsigned long int));
	else if (ft_strcmp(params->length, "j") == 0)
		num = (uintmax_t)(va_arg(params->args, uintmax_t));
	else if (ft_strcmp(params->length, "z") == 0)
		num = (size_t)(va_arg(params->args, size_t));
	else
		num = (unsigned int)(va_arg(params->args, unsigned int));
	num = (uintmax_t)num;
	return (num);
}

static void			set_params(t_params *params)
{
	int			num_len;

	params->unumber = get_number(params);
	params->string = ft_itoa_base(params->unumber, 8, 'x');
	num_len = ft_strlen(params->string);
	if (params->precision && params->precision > num_len)
		params->not_blank += params->precision - num_len;
	if (params->unumber == 0 && params->precision == 0)
		params->gap++;
	if (params->width && params->width > num_len)
		params->gap += params->width - num_len;
	if (params->width > params->precision)
		params->gap -= params->not_blank;
	else
		params->gap = 0;
	if (params->flag[4] == '#' && params->unumber != 0)
	{
		params->gap -= 1;
		params->pc += 1;
	}
	params->pc += params->gap + num_len + params->not_blank;
}

static void			print_preffix(t_params *params)
{
	if (params->flag[4] == '#' && params->unumber != 0)
		write(1, "0", 1);
}

static void		handle_flag_zero_precison(t_params *p)
{
	if (p->precision > -1)
	{
		print_padding(' ', p->gap);
		print_preffix(p);
	}
	else
	{
		print_preffix(p);
		print_padding('0', p->gap);
	}
}

void				print_o(t_params *params)
{
	set_params(params);
	if (params->unumber == 0 && params->precision == 0)
		print_padding(' ', params->gap);
	else if (params->flag[0] == '-')
	{
		print_preffix(params);
		print_not_blank(params);
		ft_putstr(params->string);
		print_padding(' ', params->gap);
	}
	else if (params->flag[1] == '0')
	{
		handle_flag_zero_precison(params);
		print_padding('0', params->not_blank);
		ft_putstr(params->string);
	}
	else
	{
		print_padding(' ', params->gap);
		print_preffix(params);
		print_not_blank(params);
		ft_putstr(params->string);
	}
	free(params->string);
}
