/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:16:41 by vomelchu          #+#    #+#             */
/*   Updated: 2018/04/04 19:00:08 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t n)
{
	int			q;
	char		*str1;
	const char	*str2;

	q = 0;
	str1 = dest;
	str2 = source;
	if (str2 < str1)
	{
		while (n--)
			str1[n] = str2[n];
	}
	else
		ft_memcpy(str1, str2, n);
	return (str1);
}
