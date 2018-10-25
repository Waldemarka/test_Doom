/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 12:23:04 by vomelchu          #+#    #+#             */
/*   Updated: 2018/08/29 12:23:05 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

SDL_Surface	*guns(t_data *data)
{
	if (data->count == 0 && data->nb_weapon == 1)
		return (data->pist[0]);
	if (data->count == 1 && data->nb_weapon == 1)
		return (data->pist[1]);
	if (data->count == 2 && data->nb_weapon == 1)
		return (data->pist[2]);
	if (data->count == 0 && data->nb_weapon == 2)
		return (data->drob[0]);
	if (data->count == 1 && data->nb_weapon == 2)
		return (data->drob[1]);
	if (data->count == 2 && data->nb_weapon == 2)
		return (data->drob[2]);
	if (data->count == 3 && data->nb_weapon == 2)
		return (data->drob[3]);
	if (data->count == 4 && data->nb_weapon == 2)
		return (data->drob[4]);
	if (data->count == 5 && data->nb_weapon == 2)
		return (data->drob[5]);
	if (data->count == 6 && data->nb_weapon == 2)
		return (data->drob[6]);
	return (NULL);
}

void		check_sprit(t_data *data)
{
	if (data->nb_weapon == 1)
	{
		data->sprit.iterat = 3;
		data->sprit.timing = 150;
		data->sprit.pixel_wid = 256;
		data->sprit.min_coord_x = WIDTH - data->sprit.pixel_wid - 100;
	}
	else if (data->nb_weapon == 2)
	{
		data->sprit.iterat = 7;
		data->sprit.timing = 120;
		data->sprit.pixel_wid = 410;
		data->sprit.min_coord_x = WIDTH - data->sprit.pixel_wid - 100;
	}
	data->sprit.min_coord_y = HEIGHT - data->sprit.pixel_wid;
	data->sprit.max_coord_x = WIDTH - 100;
	data->sprit.max_coord_y = HEIGHT;
}

void		animat(t_data *data, SDL_Surface *tex_sprite)
{
	int x;
	int y;
	int i;

	data->spr_x = 0;
	x = data->sprit.min_coord_x;
	while (x != data->sprit.max_coord_x)
	{
		data->spr_y = 0;
		y = data->sprit.min_coord_y;
		while (y != data->sprit.max_coord_y)
		{
			if ((i = get_pixel_int(tex_sprite, data->spr_x, data->spr_y)))
				data->buf[y][x] = i;
			data->spr_y++;
			y++;
		}
		data->spr_x++;
		x++;
	}
}

void		draw_animations(t_data *data)
{
	data->time = SDL_GetTicks();
	if (data->key_space == 1)
	{
		if (data->time <= data->start_time + (data->sprit.timing
			* (data->count + 1)))
			animat(data, guns(data));
		if (data->time >= data->start_time + (data->sprit.timing
			* (data->count + 1)))
		{
			animat(data, guns(data));
			data->count++;
		}
		if (data->count >= data->sprit.iterat)
		{
			data->count = 0;
			data->key_space = 0;
		}
	}
	if (data->key_space == 0)
		data->count = 0;
}

void		sprites(t_data *data)
{
	check_sprit(data);
	if (data->key_space == 0)
		animat(data, guns(data));
	if (data->key_space == 1)
		draw_animations(data);
}
