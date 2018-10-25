/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 15:04:28 by vomelchu          #+#    #+#             */
/*   Updated: 2018/04/16 05:53:43 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ismax(unsigned long long res, int i, int znak)
{
	if ((res > 9223372036854775807 || i >= 19) && znak == 1)
		return (-1);
	if ((res > 9223372036854775807 || i >= 19) && znak == -1)
		return (0);
	return (2);
}

static int	isspace(char ch)
{
	if (ch == ' ' || ch == '\n' || ch == '\t' ||
		ch == '\v' || ch == '\f' || ch == '\r')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int					q;
	int					znak;
	unsigned long long	res;
	int					i;

	q = 0;
	znak = 1;
	res = 0;
	i = 0;
	while (isspace(str[q]) == 1)
		q++;
	if (str[q] == '-' || str[q] == '+')
	{
		if (str[q++] == '-')
			znak = (-1);
	}
	while (str[q] <= '9' && str[q] >= '0')
	{
		res = (res * 10) + ((unsigned long long int)str[q] - '0');
		if (ismax(res, i, znak) != 2)
			return (ismax(res, i, znak));
		i++;
		q++;
	}
	return (res * znak);
}
