/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstrdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:33:26 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/06/19 09:06:39 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

int	ft_isstrdigit(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	if (str[i] == '-')
	{
		if (str[i + 1])
			i++;
		else
			return (-1);
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]) != 1)
			return (-1);
		i++;
	}
	return (1);
}
