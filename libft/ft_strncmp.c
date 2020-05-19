/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:16:29 by anazri            #+#    #+#             */
/*   Updated: 2019/06/30 11:05:55 by anazri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;
	int	j;

	if (n == 0)
		return (n);
	i = 0;
	j = 0;
	while (s1[i] && s2[j] && (s1[i] == s2[j]) && --n)
	{
		i++;
		j++;
	}
	return ((((unsigned char *)s1)[i]) - (((unsigned char *)s2)[i]));
}
