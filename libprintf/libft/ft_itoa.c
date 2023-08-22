/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:46:32 by hgeffroy          #+#    #+#             */
/*   Updated: 2022/11/10 16:02:24 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_revstr(char *s)
{
	int		i;
	int		len;
	char	temp;

	len = 0;
	while (s[len])
		len++;
	i = 0;
	while (i < len / 2)
	{
		temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
		i++;
	}
	return (s);
}

static int	size_itoa(long int nb)
{
	int				sizenb;

	sizenb = 0;
	if (nb <= 0)
	{
		sizenb += 1;
		nb *= -1;
	}
	while (nb > 0)
	{
		sizenb += 1;
		nb /= 10;
	}
	return (sizenb);
}

char	*ft_itoa(int n)
{
	long int		nb;
	int				i;
	char			*res;

	nb = n;
	res = (char *) malloc(sizeof(char) * ((size_itoa(nb)) + 1));
	if (!res)
		return (NULL);
	if (n < 0)
		nb *= -1;
	i = 0;
	while (nb > 0)
	{
		res[i] = nb % 10 + '0';
		nb /= 10;
		i++;
	}
	if (n < 0)
		res[i++] = '-';
	if (n == 0)
		res[i++] = '0';
	res[i] = '\0';
	return (ft_revstr(res));
}
