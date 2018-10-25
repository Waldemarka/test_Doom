/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 12:42:49 by vomelchu          #+#    #+#             */
/*   Updated: 2018/09/01 12:44:58 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	key_left(t_data *data)
{
	double plan;
	double dr;

	dr = DIR_X;
	DIR_X = DIR_X * cos(0.05) - DIR_Y * sin(0.05);
	DIR_Y = dr * sin(0.05) + DIR_Y * cos(0.05);
	plan = PLAN_X;
	PLAN_X = PLAN_X * cos(0.05) - PLAN_Y * sin(0.05);
	PLAN_Y = plan * sin(0.05) + PLAN_Y * cos(0.05);
}

void	key_right(t_data *data)
{
	double plan;
	double dr;

	dr = DIR_X;
	DIR_X = DIR_X * cos(-0.05) - DIR_Y * sin(-0.05);
	DIR_Y = dr * sin(-0.05) + DIR_Y * cos(-0.05);
	plan = PLAN_X;
	PLAN_X = PLAN_X * cos(-0.05) - PLAN_Y * sin(-0.05);
	PLAN_Y = plan * sin(-0.05) + PLAN_Y * cos(-0.05);
}

void	music_key(t_data *data, const Uint8 *keys)
{
	if (keys[SDL_SCANCODE_KP_1] && data->nbr_sky != 0)
	{
		data->nbr_sky = 0;
		Mix_PlayMusic(data->mus[0], 1);
	}
	if (keys[SDL_SCANCODE_KP_2] && data->nbr_sky != 1)
	{
		data->nbr_sky = 1;
		Mix_PlayMusic(data->mus[1], 1);
	}
	if (keys[SDL_SCANCODE_KP_3] && data->nbr_sky != 2)
	{
		data->nbr_sky = 2;
		Mix_PlayMusic(data->mus[2], 1);
	}
}

void	more_keys(t_data *data, const Uint8 *keys)
{
	if (keys[SDL_SCANCODE_1])
		data->key_floor = 1;
	if (keys[SDL_SCANCODE_2])
		data->key_floor = 2;
	if (keys[SDL_SCANCODE_3])
		data->key_floor = 3;
	if (keys[SDL_SCANCODE_4])
		data->key_floor = 4;
	if (keys[SDL_SCANCODE_LSHIFT] == 1)
		data->speed = 0.1;
	else
		data->speed = 0.06;
}

void	other_keys(t_data *data, const Uint8 *keys)
{
	static unsigned int tim;

	if (keys[SDL_SCANCODE_SPACE] && data->key_space != 1)
	{
		Mix_PlayMusic(data->shots[data->nb_weapon - 1], 1);
		data->key_space = 1;
		data->start_time = SDL_GetTicks();
	}
	if (keys[SDL_SCANCODE_Q] && data->key_space == 0
		&& tim + 200 < SDL_GetTicks())
	{
		if (data->nb_weapon == 1)
			data->nb_weapon = 2;
		else if (data->nb_weapon == 2)
			data->nb_weapon = 1;
		tim = SDL_GetTicks();
	}
	if (keys[SDL_SCANCODE_E] && data->key_door != 1)
	{
		data->door_cen = 1;
		data->start_time_door = SDL_GetTicks();
	}
	more_keys(data, keys);
	music_key(data, keys);
}
