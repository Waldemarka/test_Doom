/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 16:33:45 by vomelchu          #+#    #+#             */
/*   Updated: 2018/04/16 00:38:10 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict dest, const char *restrict append)
{
	int q;
	int i;

	q = 0;
	i = 0;
	while (dest[q] != '\0')
		q++;
	while (append[i] != '\0')
	{
		dest[q] = append[i];
		i++;
		q++;
	}
	dest[q] = '\0';
	return (dest);
}
