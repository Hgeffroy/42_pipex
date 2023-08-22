/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:49:22 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/05/26 11:11:52 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header/libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	int	i;

	if (!haystack && n == 0)
		return (NULL);
	i = 0;
	while (i + ft_strlen(needle) < ft_min(n, ft_strlen(haystack)) + 1)
	{
		if (ft_strncmp(haystack + i, needle, ft_strlen(needle)) == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
