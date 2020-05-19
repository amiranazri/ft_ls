/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 18:18:29 by anazri            #+#    #+#             */
/*   Updated: 2019/06/12 18:21:47 by anazri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*temp;

	i = 0;
	if (!(temp = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (*s)
	{
		temp[i] = f(*s);
		s++;
		i++;
	}
	return (temp);
}
