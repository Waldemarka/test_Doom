/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 20:20:00 by vomelchu          #+#    #+#             */
/*   Updated: 2018/05/21 17:42:26 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_joinfree(char *s1, char *s2, int j)
{
	size_t	i;
	char	*res;
	int		z;

	z = -1;
	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(res = (char *)malloc(i + 1)))
		return (0);
	res[i] = '\0';
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	while (s2[++z])
		res[i + z] = s2[z];
	if (j == 3 || j == 1)
		free(s1);
	return (res);
}

int		changeline(char **fdfile, char **line)
{
	int		q;
	int		i;
	char	*str;
	char	*tmp;

	q = -1;
	i = 0;
	tmp = *fdfile;
	while (tmp[++q])
	{
		if (tmp[q] == '\n')
		{
			*line = ft_strsub(tmp, 0, q);
			i = q;
			while (tmp[i] != '\0')
				i++;
			str = ft_strsub(tmp, q + 1, i - q);
			*fdfile = ft_strdup(str);
			free(str);
			free(tmp);
			return (1);
		}
	}
	return (0);
}

char	*first_line(char **fdfile, int fd)
{
	int		q;
	char	firstbuf[BUFF_SIZE + 1];

	while ((q = read(fd, firstbuf, BUFF_SIZE)) > 0)
	{
		firstbuf[q] = '\0';
		if (!*fdfile)
			*fdfile = ft_strdup(firstbuf);
		else
			*fdfile = ft_joinfree(*fdfile, firstbuf, 3);
	}
	return (fdfile[fd]);
}

int		get_next_line(int const fd, char **line)
{
	int			res;
	static char	*fdfile[4864];

	res = 0;
	if (!line || (fd < 0 || fd >= 4864) || (read(fd, fdfile[fd], 0) < 0))
		return (-1);
	if (!fdfile[fd])
		first_line(&fdfile[fd], fd);
	if (fdfile[fd])
		res = changeline(&fdfile[fd], line);
	if (res != 0 || fdfile[fd] == NULL || fdfile[fd][0] == '\0')
	{
		if (!res && *line)
			*line = NULL;
		return (res);
	}
	*line = fdfile[fd];
	fdfile[fd] = NULL;
	return (1);
}
