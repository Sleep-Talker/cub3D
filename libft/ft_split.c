/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 02:18:22 by almarsel          #+#    #+#             */
/*   Updated: 2019/12/18 08:18:29 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
		j++;
	}
	return (j);
}

static char	*ft_word(char const *s, char c, int i)
{
	int		j;
	int		k;
	char	*dst;

	j = 0;
	k = i;
	while (s[k] != c && s[k])
		k++;
	dst = (char *)malloc(sizeof(char) * (k - i + 2));
	if (dst == 0)
		return (0);
	while (s[i] && s[i] != c)
	{
		dst[j] = s[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

char		**ft_split(char const *s, char c)
{
	char	**dst;
	int		nword;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	nword = ft_count_words(s, c);
	dst = (char **)malloc(sizeof(char *) * (nword + 1));
	if (dst == 0)
		return (0);
	i = 0;
	j = 0;
	while (j < nword)
	{
		while (s[i] && s[i] == c)
			i++;
		dst[j] = ft_word(s, c, i);
		while (s[i] && s[i] != c)
			i++;
		j++;
	}
	dst[j] = 0;
	return (dst);
}
