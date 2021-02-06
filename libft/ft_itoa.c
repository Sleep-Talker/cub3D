/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 03:51:36 by almarsel          #+#    #+#             */
/*   Updated: 2019/12/16 14:36:37 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	nbchiffre(int n)
{
	int				i;
	unsigned int	m;

	if (!n)
		return (1);
	i = 0;
	m = n;
	if (n < 0)
	{
		i++;
		m = -n;
	}
	while (m)
	{
		m = m / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char			*res;
	unsigned int	m;
	int				i;
	int				signe;

	i = 0;
	if (!(res = (char *)malloc((nbchiffre(n) + 1) * sizeof(char))))
		return (NULL);
	signe = 0;
	if (n < 0)
	{
		res[0] = '-';
		signe = 1;
		m = -n;
	}
	else
		m = n;
	while (i < nbchiffre(n) - signe)
	{
		res[nbchiffre(n) - 1 - i] = '0' + m % 10;
		m = m / 10;
		i++;
	}
	res[nbchiffre(n)] = 0;
	return (res);
}
