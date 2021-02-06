/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:51:05 by almarsel          #+#    #+#             */
/*   Updated: 2019/12/18 10:09:20 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*copydst;
	unsigned char	*copysrc;
	unsigned int	i;

	copydst = (unsigned char *)dst;
	copysrc = (unsigned char *)src;
	i = 0;
	if (copysrc > copydst && dst != src)
	{
		while (i < len)
		{
			copydst[i] = copysrc[i];
			i++;
		}
	}
	else if (dst != src)
	{
		while (i < len)
		{
			copydst[len - i - 1] = copysrc[len - i - 1];
			i++;
		}
	}
	dst = (void *)copydst;
	return (dst);
}
