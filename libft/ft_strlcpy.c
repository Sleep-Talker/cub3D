/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:58:25 by almarsel          #+#    #+#             */
/*   Updated: 2019/12/16 15:05:47 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char			*s;
	unsigned int	i;
	size_t			y;

	y = 0;
	s = (char *)src;
	i = 0;
	while (src[y])
		y++;
	if (!size)
		return (y);
	while (src[i] && i < size - 1)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (y);
}
