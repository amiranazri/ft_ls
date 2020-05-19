/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 13:59:22 by anazri            #+#    #+#             */
/*   Updated: 2019/06/30 10:59:15 by anazri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n;

	if (needle[0] == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0])
		{
			n = 0;
			while (needle[n] != '\0' && haystack[i + n] && (i + n) < len)
			{
				if (needle[n] != haystack[i + n])
					break ;
				n++;
			}
			if (needle[n] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
