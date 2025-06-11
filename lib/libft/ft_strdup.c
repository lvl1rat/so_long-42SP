/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiqueir <bsiqueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:18:47 by bsiqueir          #+#    #+#             */
/*   Updated: 2022/07/06 01:14:59 by bsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (s[n] != '\0')
		n++;
	dup = (char *)malloc(sizeof(char) * n + 1);
	if (!dup)
		return (NULL);
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/*
Description
The function strdup are used to duplicate a string.

Return Value
This function returns a pointer to a null-terminated byte 
string, which is a duplicate of the string pointed to by s.
*/