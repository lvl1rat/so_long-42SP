/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiqueir <bsiqueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:55:34 by bsiqueir          #+#    #+#             */
/*   Updated: 2022/07/06 01:09:19 by bsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*memory;

	i = 0;
	memory = (unsigned char *)s;
	while (i < n)
	{
		memory[i] = c;
		i++;
	}
	return (memory);
}

// Ft_memset is a void function that will apply a char (c)
//inside the string (*s) a number (n) of times:
// - It creates a cast convertion (*memory) of the void type variable (*s).
// - From i (0) to n, It atributes a char (c) to memory[i] var,
//always incrementing i afterwards.
// It does not guarantee a null termination.
