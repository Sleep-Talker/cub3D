/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <almarsel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 07:09:00 by almarsel          #+#    #+#             */
/*   Updated: 2020/10/10 09:48:45 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_estim_len(unsigned long long ull, int base)
{
	int	len;

	len = 0;
	while (ull != 0)
	{
		ull /= base;
		len++;
	}
	return (len);
}

static char	*ft_in_ulltoa_base(unsigned long long ull,
				int base, char *str_ull, int len)
{
	str_ull[len] = '\0';
	while (ull != 0)
	{
		if ((ull % base) < 10)
			str_ull[len - 1] = (ull % base) + 48;
		else
			str_ull[len - 1] = (ull % base) + 55;
		ull /= base;
		len--;
	}
	return (str_ull);
}

char		*ft_ulltoa_base(unsigned long long ull, int base)
{
	char	*str_ull;
	int		len;

	if (ull == 0)
		return (ft_strdup("0"));
	str_ull = 0;
	len = ft_estim_len(ull, base);
	if (!(str_ull = malloc(sizeof(char) * (len + 1))))
		return (0);
	str_ull = ft_in_ulltoa_base(ull, base, str_ull, len);
	return (str_ull);
}
