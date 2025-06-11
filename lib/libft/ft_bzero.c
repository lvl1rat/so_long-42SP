/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiqueir <bsiqueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:58:22 by bsiqueir          #+#    #+#             */
/*   Updated: 2022/07/06 01:08:27 by bsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

// Ft_bzero is a void function that will apply a null
//char ('\0') inside a string (*s), a number (n) of times.
// - It calls the "ft_memset" function that starts by
//cast converting (*s) into a (unsigned char *memory).
// - From i (0) to n, it attributes a null char ('\0') to
//memory[i], incrementing i afterwards.
