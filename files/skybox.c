/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 18:44:13 by vomelchu          #+#    #+#             */
/*   Updated: 2018/09/07 18:44:14 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	skybox(t_data *data)
{
	int start_x;
	int x;
	int y;

	start_x = 0;
	if (DIR_Y <= 0)
		start_x = (int)(WIDTH_SKY / 2 - (DIR_X / (2 / 360.0)
			* ((double)WIDTH_SKY / 2 / 360.0)));
	else
		start_x = (int)(DIR_X / (2.0 / 360.0) * ((double)WIDTH_SKY
			/ 2 / 360.0));
	x = 0;
	while (x != WIDTH)
	{
		y = 0;
		start_x++;
		while (y != HEIGHT)
		{
			data->buf[y][x] = get_pixel_int(data->sky[data->nbr_sky],
				start_x, y);
			y++;
		}
		x++;
	}
}

void	cont_screen(t_data *data, SDL_Event event)
{
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_LSHIFT
		&& data->nb_screen == 0)
	{
		data->for_exit = 0;
		game(data);
	}
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_LSHIFT
		&& data->nb_screen == 1)
		ft_error(5);
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_LSHIFT
		&& data->nb_screen == 2)
		data->nb_screen = 3;
}

void	start_screen(t_data *data)
{
	SDL_Event	event;

	data->screen = SDL_CreateTextureFromSurface(data->ren,
		data->start_screen[data->nb_screen]);
	SDL_RenderCopy(data->ren, data->screen, NULL, NULL);
	SDL_RenderPresent(data->ren);
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT || EXIT)
			data->for_exit = 0;
		if (event.type == SDL_KEYDOWN && (event.key.keysym.sym == SDLK_UP
			|| event.key.keysym.sym == SDLK_LEFT))
		{
			if (data->nb_screen != 0)
				data->nb_screen -= 1;
		}
		if (event.type == SDL_KEYDOWN && (event.key.keysym.sym == SDLK_DOWN
			|| event.key.keysym.sym == SDLK_RIGHT))
			if (data->nb_screen <= 2)
				data->nb_screen += 1;
		cont_screen(data, event);
	}
}
