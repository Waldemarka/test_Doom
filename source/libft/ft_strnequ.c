/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 19:45:37 by vomelchu          #+#    #+#             */
/*   Updated: 2018/04/20 17:12:35 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	q;
	size_t	i;

	q = 0;
	i = n;
	if (!s1 && !s2)
		return (1);
	if (!s1 || !s2)
		return (0);
	if (n == 0)
		return (1);
	while (s1[q] != '\0' && s2[q] != '\0' && i != 0 && (s1[q] == s2[q]))
	{
		q++;
		i--;
	}
	i = n;
	if (q == i || (q == ft_strlen(s1) && q == ft_strlen(s2)))
		return (1);
	return (0);
}
