/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiqueir <bsiqueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:05:20 by bsiqueir          #+#    #+#             */
/*   Updated: 2022/07/06 20:45:59 by bsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = ft_strlen(dest);
	j = 0;
	len = ft_strlen(dest) + ft_strlen(src);
	if (size < i)
		return (ft_strlen(src) + size);
	while (src[j] && (i + 1) < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (len);
}

/*
Description 
The function concatenate strings. 
They are designed to be safer, more consistent,
and less error prone replacements for strncat(3).

Return Value 
strlcat functions return the total length of
the string they tried to create.
*/