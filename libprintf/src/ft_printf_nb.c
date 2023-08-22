/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:31:46 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/06/19 09:32:00 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	lennbr(int nb, int basesize)
{
	int			res;
	long int	longnb;

	longnb = nb;
	res = 1;
	if (longnb < 0)
	{
		res++;
		longnb *= -1;
	}
	while (longnb / basesize > 0)
	{
		res++;
		longnb /= basesize;
	}
	return (res);
}

int	printf_putnbr(int nb, int fd)
{
	ft_putnbr_fd(nb, fd);
	return (lennbr(nb, 10));
}

void	ft_puthexanbr(unsigned long long n, int up, int fd)
{
	char	*base;

	base = "0123456789abcdef";
	if (up)
		base = "0123456789ABCDEF";
	else if (n > 15)
	{
		ft_puthexanbr(n / 16, up, fd);
		ft_puthexanbr(n % 16, up, fd);
	}
	else
		ft_putchar_fd(base[n], fd);
}

int	printf_puthexanbr(unsigned long long n, int up, int fd)
{
	ft_puthexanbr(n, up, fd);
	return (lenunbr(n, 16));
}

int	printf_address(unsigned long long ptr, int fd)
{
	ft_putstr_fd("0x", fd);
	return (printf_puthexanbr(ptr, 0, fd) + 2);
}
