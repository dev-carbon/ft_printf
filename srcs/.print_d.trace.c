
	if (params->flag[0] == '-')
	{
		print_sign(params);
		print_padding('0', params->not_blank);
		ft_putnbrumax_fd(params->unumber, 1);
		print_padding(' ', params->gap);
	}
	else if (params->flag[1] == '0')
	{
		print_d_precision(params);
		print_sign(params);
		ft_putnbrumax_fd(params->unumber, 1);
	}
	else
	{
		print_padding(' ', params->gap);
		print_sign(params);
		print_padding('0', params->not_blank);
		ft_putnbrumax_fd(params->unumber, 1);
	}