/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:48:25 by hgeffroy          #+#    #+#             */
/*   Updated: 2022/11/16 09:54:37 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static int	*len_words(const char *s, char c)
{
	int	words;
	int	i;
	int	j;
	int	len;
	int	*lenwords;

	words = count_words(s, c);
	lenwords = malloc(sizeof(int) * (words));
	if (!lenwords)
		return (NULL);
	i = 0;
	j = 0;
	while (i < words)
	{
		len = 0;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
		{
			len++;
			j++;
		}
		lenwords[i++] = len;
	}
	return (lenwords);
}

static char	**malloc_strlist(const char *s, char c)
{
	int		i;
	int		*lenwords;
	char	**res;

	res = (char **) malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return (NULL);
	i = -1;
	lenwords = len_words(s, c);
	while (++i < count_words(s, c))
	{
		res[i] = malloc(sizeof(char) * (lenwords[i] + 1));
		if (!res[i])
		{
			while (i >= 0)
			{
				free(res[i]);
				i--;
			}
			free(res);
			return (NULL);
		}
	}
	free(lenwords);
	return (res);
}

char	**fill(char **res, char c, const char *s)
{
	int	i;
	int	j;
	int	startword;

	i = 0;
	j = 0;
	while (i < count_words(s, c))
	{
		while (s[j] == c)
			j++;
		startword = j;
		while (s[j] != c && s[j])
		{
			res[i][j - startword] = s[j];
			j++;
		}
		res[i][j - startword] = '\0';
		i++;
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(const char *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = malloc_strlist(s, c);
	if (!res)
		return (NULL);
	res = fill(res, c, s);
	return (res);
}
