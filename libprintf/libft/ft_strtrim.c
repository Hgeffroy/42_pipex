/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:49:31 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/05/26 11:11:52 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header/libft.h"

static int	isinset(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == ((char *)set)[i])
			return (1);
		i++;
	}
	return (0);
}

static int	start_strtrim(const char *s, const char *set)
{
	int	start;

	start = 0;
	while (s[start] && (isinset(s[start], set)))
		start++;
	return (start);
}

static int	end_strtrim(const char *s, const char *set, int start)
{
	int	end;

	if (start != (int)ft_strlen(s))
		end = ft_strlen(s) - 1;
	else
		end = start;
	while (s[end] && (isinset(s[end], set) && end > start))
		end--;
	return (end);
}

char	*ft_strtrim(const char *s, const char *set)
{
	char	*res;
	int		i;
	int		start;
	int		end;

	if (!s || !set)
		return (NULL);
	start = start_strtrim(s, set);
	end = end_strtrim(s, set, start);
	res = malloc(sizeof(char) * ((end - start) + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (start + i < end + 1 && s[i])
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
