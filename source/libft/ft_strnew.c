/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:25:23 by vomelchu          #+#    #+#             */
/*   Updated: 2018/04/16 01:13:23 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *x;

	if (!(x = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(x, size + 1);
	return (x);
}
