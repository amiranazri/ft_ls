/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 12:44:41 by anazri            #+#    #+#             */
/*   Updated: 2019/06/20 18:38:25 by anazri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t			i;
	size_t			len;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (ft_is_space(s[i]))
		i++;
	len = ft_strlen(s) - 1;
	while (len > i && ft_is_space(s[len]))
		len--;
	return (len < i) ? (ft_strdup("")) : (ft_strsub(s, i, len - i + 1));
}
