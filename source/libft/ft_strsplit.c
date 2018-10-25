/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 21:49:44 by vomelchu          #+#    #+#             */
/*   Updated: 2018/04/21 15:05:33 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		words(char const *str, char c)
{
	int q;
	int i;

	q = 0;
	i = 0;
	while (str[q] != '\0')
	{
		while (str[q] == c)
			q++;
		if (str[q] != c && str[q] != '\0')
		{
			while (str[q] != c && str[q] != '\0')
				q++;
			i++;
		}
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		q;
	int		slova;
	int		x;

	q = 0;
	if (!s || !c)
		return (NULL);
	slova = words(s, c);
	if (!(str = (char **)malloc(sizeof(char *) * slova + 1)))
		return (NULL);
	while (q != slova)
	{
		x = 0;
		str[q] = ft_sepereteword(s, c, q, x);
		q++;
	}
	str[q] = NULL;
	return (str);
}
