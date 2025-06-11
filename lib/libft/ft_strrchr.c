/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiqueir <bsiqueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:10:58 by bsiqueir          #+#    #+#             */
/*   Updated: 2022/07/06 01:37:50 by bsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*cast_s;
	char	*ret;

	ret = NULL;
	cast_s = (char *)s;
	if (c == '\0')
		return (cast_s + ft_strlen(cast_s));
	while (*cast_s != '\0')
	{
		if (*cast_s == (char)c)
			ret = cast_s;
		cast_s++;
	}
	return (ret);
}

/*
Description 
The C library function strrchr searches for the last
occurrence of the character c in the string pointed to,
by the argument s.

Return Value 
This function returns a pointer to the last occurrence
of character in str. If the value is not found,
the function returns a null pointer.
*/