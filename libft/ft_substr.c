/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:47:36 by almarsel          #+#    #+#             */
/*   Updated: 2019/12/18 08:22:06 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	l;
	char			*d;

	if (!s)
		return (NULL);
	i = 0;
	l = (unsigned int)len;
	if (ft_strlen(s) < start)
		l = 0;
	if (!(d = (char *)malloc((l + 1) * sizeof(char))))
		return (NULL);
	while (i < l && s[start + i])
	{
		d[i] = s[start + i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
