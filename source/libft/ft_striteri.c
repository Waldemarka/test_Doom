/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:36:50 by vomelchu          #+#    #+#             */
/*   Updated: 2018/04/08 18:19:22 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int q;

	q = 0;
	if (s && f)
	{
		while ((*s != '\0') && s && f)
		{
			f(q, s);
			s++;
			q++;
		}
	}
}
