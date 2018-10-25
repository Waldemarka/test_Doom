/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:35:41 by vomelchu          #+#    #+#             */
/*   Updated: 2018/04/04 16:38:22 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_newlen(const char *s)
{
	int q;
	int i;

	q = 0;
	i = 0;
	if (!s)
		return (0);
	i = ft_strlen(s);
	while (s[q] == ' ' || s[q] == '\n' || s[q] == '\t')
		q++;
	while (s[i - 1] == ' ' || s[i - 1] == '\n' || s[i - 1] == '\t')
		i--;
	if (i - q <= 0)
		return (1);
	return (i - q + 1);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		q;
	int		i;
	int		j;

	q = 0;
	i = ft_newlen(s);
	j = 0;
	if (!s)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	while (s[q] == ' ' || s[q] == '\n' || s[q] == '\t')
		q++;
	while (j != i - 1)
	{
		str[j] = s[q];
		j++;
		q++;
	}
	str[j] = '\0';
	return (str);
}
