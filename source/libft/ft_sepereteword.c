/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sepereteword.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 13:32:50 by vomelchu          #+#    #+#             */
/*   Updated: 2018/04/21 15:05:48 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_sepereteword(char const *str, char c, int wor, int i)
{
	char	*res;
	int		q;

	q = 0;
	res = NULL;
	while (str[q] != '\0')
	{
		if (str[q] == c || (q == 0 && str[q] != c))
		{
			while (str[q] == c)
				q++;
			i++;
		}
		if (wor == i - 1)
		{
			while (str[q] == c)
				q++;
			res = ft_strnewword(str, q, c);
			return (res);
		}
		if (str[q] != c && str[q] != '\0')
			while (str[q] != c && str[q] != '\0')
				q++;
	}
	return (res);
}
