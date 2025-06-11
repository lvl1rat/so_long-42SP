/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiqueir <bsiqueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 22:52:55 by bsiqueir          #+#    #+#             */
/*   Updated: 2022/10/25 04:12:14 by bsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_len(size_t n, int base)
{
	long int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n > 0)
	{
		n = n / base;
		len++;
	}
	return (len);
}

static char	*ft_utoa(unsigned int n)
{
	int			len;
	char		*str;
	long int	num;

	num = n;
	len = nb_len(num, 10);
	str = malloc ((len) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	len = len - 1;
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	return (str);
}

int	ft_unsigned(unsigned int nb)
{
	int		ret;
	char	*str;

	str = ft_utoa(nb);
	ret = ft_putstr(str);
	free(str);
	return (ret);
}

int	ft_puthex(unsigned long nb, char c)
{
	int	len;

	len = nb_len(nb, 16);
	if (nb >= 16)
	{
		ft_puthex(nb / 16, c);
		ft_puthex(nb % 16, c);
	}
	else
	{
		if (nb < 10)
			ft_putchr(nb + '0');
		else if (c == 'x')
			ft_putchr(nb + 87);
		else
			ft_putchr(nb + 55);
	}
	return (len);
}

int	ft_putptr(unsigned long nb)
{
	int	len;

	if (!nb)
		return (ft_putstr("(nil)"));
	len = write(1, "0x", 2);
	len += ft_puthex(nb, 'x');
	return (len);
}
