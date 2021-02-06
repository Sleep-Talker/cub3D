/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:04:28 by almarsel          #+#    #+#             */
/*   Updated: 2019/12/18 09:36:02 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	lendst;

	lendst = (dst ? ft_strlen(dst) : 0);
	if (lendst > size || size == 0)
		return (ft_strlen(src) + size);
	i = 0;
	while (src[i] && (lendst + i < size - 1))
	{
		dst[lendst + i] = src[i];
		i++;
	}
	dst[lendst + i] = 0;
	return (lendst + ft_strlen(src));
}
