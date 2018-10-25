/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:12:50 by vomelchu          #+#    #+#             */
/*   Updated: 2018/04/16 00:58:33 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*rech(const char *str)
{
	while (*str)
		str++;
	return ((char *)str);
}

char			*ft_strrchr(const char *str, int ch)
{
	int i;

	i = ft_strlen(str);
	if (ch == '\0' || ch == 256)
		return (rech(str));
	while (i--)
	{
		if (str[i] == (char)ch)
			return ((char *)&str[i]);
	}
	return (NULL);
}
