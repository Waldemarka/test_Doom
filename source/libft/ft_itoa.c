/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 12:52:17 by vomelchu          #+#    #+#             */
/*   Updated: 2018/04/04 15:45:39 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		intlength(int n)
{
	int q;

	q = 0;
	if (n < 0)
	{
		q++;
		n = n * (-1);
	}
	while (n >= 10)
	{
		n = n / 10;
		q++;
	}
	return (q + 1);
}

static char		*plus(int n)
{
	char	*str;
	int		q;
	int		sym;

	q = 0;
	sym = intlength(n);
	if (!(str = (char *)malloc(sizeof(char) * sym + 1)))
		return (NULL);
	str[sym] = '\0';
	while (n >= 10 && sym >= 2)
	{
		str[sym - 1] = n % 10 + '0';
		sym--;
		n = n / 10;
	}
	str[0] = n + '0';
	return (str);
}

static char		*minus(int n)
{
	char	*str;
	int		q;
	int		sym;

	q = 0;
	sym = intlength(n);
	if (!(str = (char *)malloc(sizeof(char) * sym + 1)))
		return (NULL);
	str[sym] = '\0';
	n = n * (-1);
	while (n >= 10 && sym >= 3)
	{
		str[sym - 1] = n % 10 + '0';
		sym--;
		n = n / 10;
	}
	str[1] = n + '0';
	str[0] = '-';
	return (str);
}

static char		*zero(int n)
{
	char *str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	str[0] = n + '0';
	str[1] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	char *str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n > -2147483648 && n <= 2147483647)
	{
		if (n > 0)
			str = plus(n);
		if (n < 0)
			str = minus(n);
		if (n == 0)
			str = zero(n);
	}
	else
		str = NULL;
	return (str);
}
