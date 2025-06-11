/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiqueir <bsiqueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:21:26 by bsiqueir          #+#    #+#             */
/*   Updated: 2022/07/06 01:15:20 by bsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sum;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	sum = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		sum[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		sum[i] = s2[j];
		j++;
		i++;
	}
	sum[i] = '\0';
	return (sum);
}

/*
Description 
Allocates (with malloc(3)) and returns a “fresh” string ending
with ’\0’, result of the concatenation of s1 and s2. If
the allocation fails the function returns NULL.

Return Value
The “fresh” string result of the concatenation of the 2 strings.
*/