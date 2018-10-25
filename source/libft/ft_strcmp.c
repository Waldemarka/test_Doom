/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:34:40 by vomelchu          #+#    #+#             */
/*   Updated: 2018/04/03 17:15:39 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *str1, const char *str2)
{
	int q;

	q = 0;
	while (str1[q] == str2[q] && str1[q] != '\0' && str2[q] != '\0')
	{
		q++;
	}
	return ((unsigned char)str1[q] - (unsigned char)str2[q]);
}
