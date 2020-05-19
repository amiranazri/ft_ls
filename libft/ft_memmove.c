/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 10:08:06 by anazri            #+#    #+#             */
/*   Updated: 2019/06/19 15:49:24 by anazri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	if (src > dst)
	{
		d = dst;
		s = (char *)src;
		while (len--)
			*d++ = *s++;
	}
	else if (dst > src)
		ft_memcpy(dst, src, len);
	return (dst);
}
