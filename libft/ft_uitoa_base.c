/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <almarsel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 15:44:50 by almarsel          #+#    #+#             */
/*   Updated: 2020/10/04 16:22:12 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_estim_len(unsigned int ui, int base)
{
	int	len;

	len = 0;
	while (ui != 0)
	{
		ui /= base;
		len++;
	}
	return (len);
}

static char	*ft_in_uitoa_base(unsigned int ui, int base, char *str_ui, int len)
{
	str_ui[len] = '\0';
	while (ui != 0)
	{
		if ((ui % base) < 10)
			str_ui[len - 1] = (ui % base) + 48;
		else
			str_ui[len - 1] = (ui % base) + 55;
		ui /= base;
		len--;
	}
	return (str_ui);
}

char		*ft_uitoa_base(unsigned int ui, int base)
{
	char	*str_ui;
	int		len;

	if (ui == 0)
		return (ft_strdup("0"));
	str_ui = 0;
	len = ft_estim_len(ui, base);
	if (!(str_ui = malloc(sizeof(char) * (len + 1))))
		return (0);
	str_ui = ft_in_uitoa_base(ui, base, str_ui, len);
	return (str_ui);
}
