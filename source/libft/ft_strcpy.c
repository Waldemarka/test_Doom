/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:58:51 by vomelchu          #+#    #+#             */
/*   Updated: 2018/03/23 16:00:45 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *source)
{
	int q;

	q = 0;
	while (source[q] != '\0')
	{
		dest[q] = source[q];
		q++;
	}
	dest[q] = '\0';
	return (dest);
}
