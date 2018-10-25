/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnewword.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 13:33:42 by vomelchu          #+#    #+#             */
/*   Updated: 2018/04/21 15:05:11 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnewword(char const *stroka, int index, char c)
{
	char	*str;
	int		q;
	int		j;

	q = 0;
	j = index;
	while (stroka[j] != '\0' && stroka[j] != c)
		j++;
	if (!(str = (char *)malloc(sizeof(char) * j - index + 1)))
		return (NULL);
	q = 0;
	while (stroka[index] != '\0' && stroka[index] != c)
	{
		str[q] = stroka[index];
		q++;
		index++;
	}
	str[q] = '\0';
	return (str);
}
