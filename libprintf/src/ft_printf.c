/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:27:27 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/07/17 23:55:56 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_args(char c, va_list args, int fd)
{
	int	res;

	res = 0;
	if (c == 'c')
		res = printf_putchar(va_arg(args, int), fd);
	else if (c == 'd' || c == 'i')
		res = printf_putnbr(va_arg(args, int), fd);
	else if (c == 's')
		res = printf_putstr((const char *)va_arg(args, char *), fd);
	else if (c == 'u')
		res = printf_putunbr(va_arg(args, unsigned int), fd);
	else if (c == 'p')
		res = printf_address(va_arg(args, unsigned long long), fd);
	else if (c == 'x')
		res = printf_puthexanbr(va_arg(args, unsigned int), 0, fd);
	else if (c == 'X')
		res = printf_puthexanbr(va_arg(args, unsigned int), 1, fd);
	else if (c == '%')
	{
		ft_putchar_fd('%', fd);
		res = 1;
	}
	return (res);
}

int	ft_printf_main(const char *str, va_list args, const char *modes, int fd)
{
	int	res;
	int	mode;
	int	i;

	i = 0;
	res = 0;
	mode = 0;
	while (str[i])
	{
		if (str[i] == '%' && (mode % 2) == 0)
			mode++;
		else if ((mode % 2) == 1 && ft_strchr(modes, str[i]))
		{
			res += print_args(str[i], args, fd);
			mode++;
		}
		else if (mode % 2 == 0)
			res += printf_putchar(str[i], fd);
		else
			return (va_end(args), -1);
		i++;
	}
	return (res);
}

int	ft_printf(const char *str, ...)
{
	int			res;
	va_list		args;
	const char	*modes;

	if (write(1, 0, 0) != 0)
		return (-1);
	modes = "cdisupxX%";
	if (!str)
		return (-1);
	va_start(args, str);
	res = ft_printf_main(str, args, modes, 1);
	va_end(args);
	return (res);
}

int	ft_dprintf(int fd, const char *str, ...)
{
	int			res;
	va_list		args;
	const char	*modes;

	if (write(fd, 0, 0) != 0)
		return (-1);
	modes = "cdisupxX%";
	if (!str)
		return (-1);
	va_start(args, str);
	res = ft_printf_main(str, args, modes, fd);
	va_end(args);
	return (res);
}
