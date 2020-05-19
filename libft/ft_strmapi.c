/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 18:22:03 by anazri            #+#    #+#             */
/*   Updated: 2019/06/12 18:27:37 by anazri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*con;

	i = 0;
	if (!(con = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (*s)
	{
		con[i] = f(i, *s);
		s++;
		i++;
	}
	return (con);
}
