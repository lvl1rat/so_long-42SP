/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiqueir <bsiqueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:20:27 by bsiqueir          #+#    #+#             */
/*   Updated: 2022/07/07 02:46:13 by bsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	if (((s_len - start) > len) && (start < s_len))
		sub = malloc(sizeof(char) * len + 1);
	else if (start > s_len)
		sub = malloc(sizeof(char));
	else
		sub = malloc(sizeof(char) * (s_len - start) + 1);
	if (!sub)
		return (NULL);
	if (start < s_len)
	{
		while (s[start] && i < len)
			sub[i++] = s[start++];
	}
	sub[i] = '\0';
	return (sub);
}

/*
Description 
Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’.

Return Value 
The substring.
NULL if the allocation fails.
*/