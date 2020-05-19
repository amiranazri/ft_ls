/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 11:19:19 by anazri            #+#    #+#             */
/*   Updated: 2019/06/13 09:35:28 by anazri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_token_count(char *str, int c)
{
	int		i;
	size_t	count;
	t_bool	tested;

	i = 0;
	tested = false;
	count = 0;
	while (str[i])
	{
		if (str[i] == c && tested == false)
			count += 1;
		else if (str[i] == c && tested == true)
			i++;
		else
			tested = false;
		i++;
	}
	return (count);
}
