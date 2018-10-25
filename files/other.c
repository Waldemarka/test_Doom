/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 18:15:35 by vomelchu          #+#    #+#             */
/*   Updated: 2018/08/09 18:15:38 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_error(int num)
{
	if (num == 0)
		ft_putstr("BAD MALLOC!\n");
	if (num == 1)
		ft_putstr("1 ARGC / DIRECTORY \n");
	if (num == 2)
		ft_putstr("BAD READ / NOT VALID MAP\n");
	if (num == 3)
		ft_putstr("INIT ERROR\n");
	if (num == 4)
		ft_putstr("BAD LOAD\n");
	exit(1);
}

int		len_int(char *str)
{
	int q;
	int i;

	q = 0;
	i = 0;
	if (str == NULL)
		return (0);
	while (str[q])
	{
		if (str[q] <= '9' && str[q] >= '0')
		{
			while (str[q] <= '9' && str[q] >= '0')
				q++;
			i++;
			q--;
		}
		q++;
	}
	return (i);
}
/*
void	check_rest(t_data *data)
{
	int q;

	q = -1;
	while (++q != data->width_arr)
		if (data->array[0][q] != 1 || data->array[data->height_arr - 1][q] != 1)
			ft_error(2);
	q = -1;
	while (++q != data->height_arr)
		if (data->array[q][0] != 1 || data->array[q][data->width_arr - 1] != 1)
			ft_error(2);
	if (data->array[(int)POS_Y][(int)POS_X] != 0)
		ft_error(2);
	if ((int)POS_Y == 0 || (int)POS_Y == 1 ||
		(int)POS_Y == data->height_arr - 1 ||
		(int)POS_Y == data->height_arr - 2)
		ft_error(2);
	if ((int)POS_X == 0 || (int)POS_X == 1 ||
		(int)POS_X == data->width_arr - 1 || (int)POS_X == data->width_arr - 2)
		ft_error(2);
}*/

void	load_other_media(t_data *data)
{
	data->pist[0] = load_image("media/guns/pist1.png");
	data->pist[1] = load_image("media/guns/pist2.png");
	data->pist[2] = load_image("media/guns/pist3.png");
	data->drob[0] = load_image("media/guns/drob1.png");
	data->drob[1] = load_image("media/guns/drob2.png");
	data->drob[2] = load_image("media/guns/drob3.png");
	data->drob[3] = load_image("media/guns/drob4.png");
	data->drob[4] = load_image("media/guns/drob5.png");
	data->drob[5] = load_image("media/guns/drob6.png");
	data->drob[6] = load_image("media/guns/drob7.png");
	data->sky[0] = load_image("media/sky/sky2.jpg");
	data->sky[1] = load_image("media/sky/sky.jpg");
	data->sky[2] = load_image("media/sky/sky1.jpg");
	data->mus[0] = load_music("media/music/Ben_Howard.mp3");
	data->mus[1] = load_music("media/music/Valentin.mp3");
	data->mus[2] = load_music("media/music/Saje_Our_Story.mp3");
	data->shots[0] = load_music("media/music/pist.mp3");
	data->shots[1] = load_music("media/music/drobov.mp3");
}

void	load_media(t_data *data)
{
	data->up = load_image("media/walls_etc/upper.png");
	data->floor = load_image("media/walls_etc/flor.jpg");
	data->wall[0] = load_image("media/walls_etc/wall1.jpg");
	data->wall[1] = load_image("media/walls_etc/wall2.jpg");
	data->wall[2] = load_image("media/walls_etc/wall3.jpg");
	data->wall[3] = load_image("media/walls_etc/wall4.jpg");
	data->wall[4] = load_image("media/door/door_1.png");
	data->wall[5] = load_image("media/door/door_2.png");
	data->wall[6] = load_image("media/door/door_3.png");
	data->wall[7] = load_image("media/door/door_4.png");
	data->wall[8] = load_image("media/door/door_5.png");
	data->wall[9] = load_image("media/door/door_6.png");
	data->wall[10] = load_image("media/door/door_7.png");
	data->wall[11] = load_image("media/door/door_8.png");
	data->wall[12] = load_image("media/door/door_9.png");
	data->start_screen[0] = load_image("media/walls_etc/start_screen_1.jpg");
	data->start_screen[1] = load_image("media/walls_etc/start_screen_2.jpg");
	data->start_screen[2] = load_image("media/walls_etc/start_screen_3.jpg");
	data->start_screen[3] = load_image("media/walls_etc/start_screen_4.jpg");
	load_other_media(data);
}
