/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 19:24:40 by vomelchu          #+#    #+#             */
/*   Updated: 2018/04/20 17:11:56 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	size_t q;

	q = 0;
	if (!s1 && !s2)
		return (1);
	if (!s1 || !s2)
		return (0);
	while (s1[q] != '\0' && s2[q] != '\0' && (s1[q] == s2[q]))
		q++;
	if (q == ft_strlen(s1) && q == ft_strlen(s2))
		return (1);
	return (0);
}
