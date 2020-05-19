/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 10:35:14 by anazri            #+#    #+#             */
/*   Updated: 2019/06/17 08:55:47 by anazri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *x;

	x = (unsigned char *)b;
	if (len)
		while (len != 0)
		{
			len--;
			*x = (unsigned char)c;
			x++;
		}
	return (b);
}
