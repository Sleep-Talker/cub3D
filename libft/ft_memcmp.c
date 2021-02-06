/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:32:33 by almarsel          #+#    #+#             */
/*   Updated: 2019/12/19 15:18:41 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*copys1;
	unsigned char	*copys2;
	unsigned int	i;

	copys1 = (unsigned char *)s1;
	copys2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (copys1[i] != copys2[i])
			return (copys1[i] - copys2[i]);
		i++;
	}
	return (0);
}
