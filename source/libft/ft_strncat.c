/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 16:42:22 by vomelchu          #+#    #+#             */
/*   Updated: 2018/03/30 17:17:38 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *append, size_t n)
{
	int q;
	int i;

	q = 0;
	i = 0;
	while (dest[q] != '\0')
		q++;
	while (append[i] != '\0' && n != 0)
	{
		dest[q] = append[i];
		n--;
		q++;
		i++;
	}
	dest[q] = '\0';
	return (dest);
}
