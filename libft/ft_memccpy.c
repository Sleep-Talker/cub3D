/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:11:35 by almarsel          #+#    #+#             */
/*   Updated: 2019/12/16 11:32:32 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*copydst;
	unsigned char	*copysrc;
	unsigned int	i;

	copydst = (unsigned char *)dst;
	copysrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		copydst[i] = copysrc[i];
		if (copysrc[i] == (unsigned char)c)
			return ((void *)(copydst + i + 1));
		i++;
	}
	return (NULL);
}
