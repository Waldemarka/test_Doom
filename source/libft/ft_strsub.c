/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 16:34:43 by vomelchu          #+#    #+#             */
/*   Updated: 2018/04/16 01:33:36 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		q;
	int		i;

	q = 0;
	i = len;
	if (s == NULL)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	while (s[start] != '\0' && i != 0)
	{
		str[q] = s[start];
		i--;
		q++;
		start++;
	}
	str[q] = '\0';
	return (str);
}
