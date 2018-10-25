/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:58:15 by vomelchu          #+#    #+#             */
/*   Updated: 2018/04/04 13:06:27 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char *str;

	if (n == 0)
		return (dest);
	str = (unsigned char *)dest;
	while (n != 0)
	{
		*str++ = (unsigned char)c;
		n--;
	}
	return (dest);
}
