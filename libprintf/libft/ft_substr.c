/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:51:53 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/05/26 11:11:52 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header/libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) - start < (unsigned int)len)
		len = (unsigned int)ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	res = malloc (sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = ((char *)s)[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
