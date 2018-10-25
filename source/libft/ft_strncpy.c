/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 16:18:41 by vomelchu          #+#    #+#             */
/*   Updated: 2018/03/30 17:14:06 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *destination, const char *source, size_t n)
{
	int q;

	q = 0;
	while (source[q] != '\0' && n != 0)
	{
		destination[q] = source[q];
		q++;
		n--;
	}
	if (n > 0)
	{
		while (n != 0)
		{
			destination[q] = '\0';
			n--;
			q++;
		}
	}
	return (destination);
}
