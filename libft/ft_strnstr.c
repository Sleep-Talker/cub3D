/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:22:54 by almarsel          #+#    #+#             */
/*   Updated: 2019/12/19 15:10:58 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *tf, size_t n)
{
	char			*cs;
	char			*ctf;
	unsigned int	i;

	cs = (char *)s;
	ctf = (char *)tf;
	i = ft_strlen(tf);
	if (*ctf == '\0')
		return (cs);
	while (*cs != '\0' && n >= i)
	{
		if (ft_strncmp(cs, ctf, i) == 0)
			return (cs);
		cs++;
		n--;
	}
	return (NULL);
}
