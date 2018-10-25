/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 18:15:43 by vomelchu          #+#    #+#             */
/*   Updated: 2018/08/09 18:15:45 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

char	**open_read(t_data *data)
{
	char	*line;
	char	*str;
	char	**ret;

	str = NULL;
	line = NULL;
	if ((data->fd = open(data->name, O_RDONLY)) == -1)
		ft_error(3);
	get_next_line(data->fd, &line);
	if (!line || ft_strlen(line) < 1)
		ft_error(2);
	str = ft_strdup(line);
	while (line != NULL)
	{
		free(line);
		str = ft_joinfree(str, "\n", 3);
		get_next_line(data->fd, &line);
		if (line != NULL)
			str = ft_joinfree(str, line, 3);
	}
	close(data->fd);
	ret = ft_strsplit(str, '\n');
	free(str);
	return (ret);
}

void	first_ar(t_data *data, char **str)
{
	if ((len_int(str[0]) != 1) || (len_int(str[1]) != 1) ||
		(len_int(str[2]) != 1) || (len_int(str[3]) != 1) ||
		((len_int(str[4]) != 1)))
		ft_error(2);
	if ((ft_isdigit(str[0][0]) != 1) || (ft_isdigit(str[1][0]) != 1)
		|| (ft_isdigit(str[2][0]) != 1) || (ft_isdigit(str[3][0]) != 1) ||
		(ft_isdigit(str[5][0]) != 1))
		ft_error(2);
	data->width_arr = ft_atoi(str[0]);
	data->height_arr = ft_atoi(str[1]);
	POS_X = (double)ft_atoi(str[2]);
	POS_Y = (double)ft_atoi(str[3]);
	data->nb_level = ft_atoi(str[4]);
	if (data->width_arr < 4 || data->height_arr < 4 ||
		POS_X > data->width_arr || POS_Y > data->height_arr)
		ft_error(2);
}

void	check_str(t_data *data, char **str)
{
	int q;
	int i;

	q = 5;
	i = 0;
	while (str[q])
	{
		if (len_int(str[q]) != data->width_arr)
			ft_error(2);
		i++;
		q++;
	}
	if (i != data->height_arr * data->nb_level)
		ft_error(2);
}

void	make_arr(t_data *data, char **str)
{
	int q;
	int i;
	int j;
	int tmp;

	q = 5;
	while (q != data->height_arr + 5)
	{
		i = 0;
		j = 0;
		while (str[q][i])
		{
			if (str[q][i] >= '0' && str[q][i] <= '6')
			{
				tmp = -1;
				while (++tmp < data->nb_level)
				{
				data->array[tmp][q - 5][j] = ft_atoi(&str[q + (tmp * data->height_arr)][i]);
					/*if (data->array[0][q - 5][j] != 4 &&
						data->array[0][q - 5][j] != 2 )
						data->array[tmp][q - 5][j] = ft_atoi(&str[q][i]);
					else if (tmp > 2)
						data->array[tmp][q - 5][j] = 0;*/
				}
				j++;
			}
			i++;
		}
		q++;
	}
}

int		**int_malloc(t_data *data)
{
	int q;
	int i;

	q = 0;
	i = 0;
	if (!(data->array = (int***)malloc(sizeof(int**) * data->nb_level)))
		ft_error(0);
	while (i != data->nb_level)
	{
		if (!(data->array[i] = (int**)malloc(sizeof(int*) * data->height_arr)))
			ft_error(0);
		q = 0;
		while (q != data->height_arr)
		{
			if (!(data->array[i][q] = (int*)malloc(sizeof(int) * data->width_arr)))
				ft_error(0);
			q++;
		}
		i++;
	}
	return (*data->array);
}