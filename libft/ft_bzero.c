/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 11:10:42 by almarsel          #+#    #+#             */
/*   Updated: 2019/12/16 11:18:58 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*copy;
	unsigned int	i;

	i = 0;
	copy = (unsigned char*)s;
	while (i < n)
	{
		copy[i] = 0;
		i++;
	}
	s = (void*)copy;
}
