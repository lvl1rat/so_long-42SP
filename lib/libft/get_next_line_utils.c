/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiqueir <bsiqueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 01:19:07 by bsiqueir          #+#    #+#             */
/*   Updated: 2022/10/25 04:02:50 by bsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	needs_null(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		return (1);
	return (0);
}

char	*ft_gnl_substr(char const *s, unsigned int start, size_t len)
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

char	*ft_gnl_strchr(const char *str, int c)
{
	int		i;
	char	*new;

	if (!str || !c)
		return (NULL);
	i = 0;
	new = (char *)str;
	while (new[i])
	{
		if (new[i] == (char) c)
			return (&new[i]);
		i++;
	}
	return (0);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}
