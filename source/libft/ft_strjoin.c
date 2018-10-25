/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 01:25:40 by vomelchu          #+#    #+#             */
/*   Updated: 2018/04/16 02:15:46 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	q;
	size_t	i;
	int		j;

	q = -1;
	if (s1 == NULL && s2 == NULL)
		return ((char *)s2);
	if (s1 == NULL && s2 != NULL)
		return ((char *)s2);
	if (s1 != NULL && s2 == NULL)
		return ((char *)s1);
	i = ft_strlen(s1) + ft_strlen(s2);
	j = 0;
	if (!(str = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	while (++q != ft_strlen(s1))
		str[q] = s1[q];
	while (q != i)
		str[q++] = s2[j++];
	str[q] = '\0';
	return (str);
}
