/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:17:45 by vomelchu          #+#    #+#             */
/*   Updated: 2018/03/30 15:18:36 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t n)
{
	size_t			q;
	char			*str1;
	const char		*str2;

	q = 0;
	str1 = dest;
	str2 = source;
	while (q != n)
	{
		str1[q] = str2[q];
		q++;
	}
	return (dest);
}
