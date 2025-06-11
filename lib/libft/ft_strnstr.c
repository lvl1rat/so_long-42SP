/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiqueir <bsiqueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 01:34:37 by bsiqueir          #+#    #+#             */
/*   Updated: 2022/07/06 22:45:17 by bsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*cast_s1;

	i = 0;
	cast_s1 = (char *)s1;
	if (ft_strlen(s2) == 0)
		return (cast_s1);
	while (cast_s1[i] != '\0' && n >= ft_strlen(s2))
	{
		if (ft_strncmp(&cast_s1[i], s2, ft_strlen(s2)) == 0)
		{
			if (ft_strlen(s2) > n)
				return (NULL);
			return (&cast_s1[i]);
		}
		n--;
		i++;
	}
	return (NULL);
}

/*Description 
The strnstr function locates the first occurrence of
the null-terminated string little in the string big.

Return Value 
If    little is an empty string, big is returned; if little occurs nowhere
in    big, NULL is returned; otherwise a pointer to the first    character of
the first occurrence of little is returned.*/