/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 11:19:56 by almarsel          #+#    #+#             */
/*   Updated: 2019/12/18 10:47:05 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*copysrc;
	unsigned char	*copydst;
	unsigned int	i;

	i = 0;
	copysrc = (unsigned char *)src;
	copydst = (unsigned char *)dest;
	if (dest == src)
		return (dest);
	while (i < n)
	{
		copydst[i] = copysrc[i];
		i++;
	}
	dest = (void *)copydst;
	return (dest);
}
