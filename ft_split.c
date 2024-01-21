/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:43:06 by mben-yah          #+#    #+#             */
/*   Updated: 2024/01/20 19:19:26 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_words(const char *str, char c)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((str[i + 1] == c || !str[i + 1]) && str[i] != c)
			count++;
		i++;
	}
	return (count);
}

static	char	**__clean(char **tmp)
{
	size_t	i;

	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
	return (NULL);
}

static	char	**__fill(const char *s, char c, char **tmp, int word_count)
{
	size_t	i;
	size_t	a;
	size_t	start;
	size_t	len;

	a = 0;
	i = 0;
	while (word_count--)
	{
		len = 0;
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i])
		{
			len += 1;
			i++;
		}
		*(tmp + a) = malloc((len + 1) * sizeof(char));
		if (!(*(tmp + a)))
			return (__clean(tmp));
		ft_strlcpy(tmp[a++], s + start, len + 1);
	}
	tmp[a] = 0;
	return (tmp);
}

char	**ft_split(char const *s, char c)
{
	char	**tmp;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	tmp = malloc((word_count + 1) * sizeof(char *));
	if (!tmp)
		return (0);
	tmp = __fill(s, c, tmp, word_count);
	return (tmp);
}
