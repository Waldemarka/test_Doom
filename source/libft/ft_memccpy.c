/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:03:51 by vomelchu          #+#    #+#             */
/*   Updated: 2018/03/30 15:21:20 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int c, size_t n)
{
	int				q;
	unsigned char	*str1;
	const char		*str2;

	q = 0;
	str1 = dest;
	str2 = source;
	while (n != 0)
	{
		str1[q] = str2[q];
		if (str1[q] == (unsigned char)c)
			return (&str1[q + 1]);
		q++;
		n--;
	}
	return (NULL);
}
