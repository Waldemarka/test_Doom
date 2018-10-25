/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:51:49 by vomelchu          #+#    #+#             */
/*   Updated: 2018/04/16 00:42:24 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	int q;
	int i;

	i = 0;
	if (ft_strlen(str2) == 0)
		return ((char *)str1);
	while (*str1 != '\0')
	{
		q = 0;
		i = 0;
		while (str1[q] == str2[i])
		{
			if (str2[i + 1] == '\0')
				return ((char *)str1);
			if (str1[q + 1] == '\0')
				return (NULL);
			q++;
			i++;
		}
		str1++;
	}
	return (NULL);
}
