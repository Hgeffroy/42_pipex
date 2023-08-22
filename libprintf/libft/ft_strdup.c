/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:48:35 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/05/26 11:11:52 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char		*sdup;
	size_t		len;
	int			i;

	len = ft_strlen(s);
	sdup = (char *)malloc(sizeof(char) * (len + 1));
	if (!sdup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		sdup[i] = ((char *)s)[i];
		i++;
	}
	sdup[i] = ((char *)s)[i];
	return (sdup);
}
