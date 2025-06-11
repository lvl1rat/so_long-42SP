/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiqueir <bsiqueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 00:45:12 by bsiqueir          #+#    #+#             */
/*   Updated: 2022/07/09 01:49:35 by bsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_w_counter(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			j++;
		if (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c)
			j++;
		i++;
	}
	return (j);
}

static void	**free_m(char **f)
{
	free(f);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		i;
	int		j;
	int		save;

	i = 0;
	j = 0;
	ret = malloc(sizeof(char *) * (ft_w_counter(s, c) + 1));
	if (!ret || !s)
		free_m(ret);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		save = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > save)
			ret[j++] = ft_substr((s + save), 0, (i - save));
	}
	ret[j] = NULL;
	return (ret);
}

/*
Description 
Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer.

Return Value 
The array of new strings resulting from the split.
NULL if the allocation fails.
*/