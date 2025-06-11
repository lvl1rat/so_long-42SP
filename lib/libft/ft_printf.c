/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiqueir <bsiqueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 22:21:54 by bsiqueir          #+#    #+#             */
/*   Updated: 2022/10/25 04:12:21 by bsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		ret;
	va_list	arg;

	i = 0;
	ret = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ret += convert(arg, str[i]);
		}
		else
		{
			ft_putchr(str[i]);
			ret++;
		}
		i++;
	}
	va_end(arg);
	return (ret);
}

int	convert(va_list arg, char c)
{
	int	ret;

	if (c == 's')
		ret = ft_putstr(va_arg(arg, char *));
	else if (c == 'c')
		ret = ft_putchr(va_arg(arg, int));
	else if (c == 'i' || c == 'd')
		ret = ft_putnb(va_arg(arg, int));
	else if (c == 'u')
		ret = ft_unsigned(va_arg(arg, unsigned int));
	else if (c == 'x' || c == 'X')
		ret = ft_puthex(va_arg(arg, unsigned int), c);
	else if (c == 'p')
		ret = ft_putptr(va_arg(arg, unsigned long));
	else
		ret = ft_putchr(c);
	return (ret);
}
