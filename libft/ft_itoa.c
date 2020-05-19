/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlinde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:17:42 by dlinde            #+#    #+#             */
/*   Updated: 2019/06/30 11:12:55 by anazri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(int num)
{
	size_t	i;

	i = 1;
	while (num /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char			*str;
	unsigned int	i;
	size_t			len;

	len = ft_size(n);
	i = n;
	if (n < 0)
	{
		i = -n;
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	len = len - 1;
	str[len] = i % 10 + 48;
	while (i /= 10)
		str[--len] = i % 10 + 48;
	(n < 0) ? str[0] = 45 : 0;
	return (str);
}
