/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiqueir <bsiqueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:15:25 by bsiqueir          #+#    #+#             */
/*   Updated: 2022/07/06 23:17:52 by bsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	ret;

	i = 0;
	ret = 0;
	sign = 1;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\f'
		|| nptr[i] == '\v' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= (-1);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		ret *= 10;
		ret += sign * (nptr[i] - '0');
		i++;
	}
	return (ret);
}

//This function will turn ASCII chars to int by searching trough
//each individual string character (nptr[i]).
