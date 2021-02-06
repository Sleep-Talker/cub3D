/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 09:41:06 by almarsel          #+#    #+#             */
/*   Updated: 2019/12/16 11:49:30 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*copy;
	unsigned int	i;

	copy = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		copy[i] = (unsigned char)c;
		i++;
	}
	return ((void *)copy);
}
