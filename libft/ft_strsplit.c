/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:03:25 by anazri            #+#    #+#             */
/*   Updated: 2019/06/30 11:28:33 by anazri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		split_words(char **result, const char *str, int c)
{
	char	*start;
	size_t	i;
	size_t	current;

	i = 0;
	current = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			start = (char *)str + i;
			while (str[i] != c && str[i] != 0)
				i++;
			result[current] = ft_strndup(start, str + i - start);
			current++;
		}
	}
	result[current] = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	wc;
	size_t	i;
	char	**ret;

	wc = 0;
	i = 0;
	if (s == NULL || c == 0)
		return (NULL);
	wc = ft_token_count((char *)s, c);
	if (!(ret = (char **)malloc(sizeof(char *) * (wc + 1))))
		return (NULL);
	split_words(ret, s, c);
	return (ret);
}
