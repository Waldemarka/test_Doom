/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:26:50 by vomelchu          #+#    #+#             */
/*   Updated: 2018/04/15 23:41:03 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *dest, int c, size_t n)
{
	unsigned char	q;
	unsigned char	*str1;

	q = (unsigned char)c;
	str1 = (unsigned char *)dest;
	while (n)
	{
		if (*str1 == q)
			return (str1);
		str1++;
		n--;
	}
	return (NULL);
}
