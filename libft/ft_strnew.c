/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 10:24:05 by anazri            #+#    #+#             */
/*   Updated: 2019/06/19 18:56:41 by anazri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *store;

	if (!(store = ft_memalloc(size + 1)))
		return (NULL);
	ft_strncpy(store, "\0", size + 1);
	return (store);
}
