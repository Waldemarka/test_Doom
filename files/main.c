/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 11:13:20 by vomelchu          #+#    #+#             */
/*   Updated: 2018/08/12 11:13:21 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_all(t_data *data)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		ft_error(3);
	if (!(data->win = SDL_CreateWindow("Wolf3D", 400, 400, WIDTH,
		HEIGHT, SDL_WINDOW_RESIZABLE)))
		ft_error(3);
	if (!(data->ren = SDL_CreateRenderer(data->win, -1, SDL_RENDERER_ACCELERATED
		| SDL_RENDERER_PRESENTVSYNC)))
		ft_error(3);
	if (!(data->screen = SDL_CreateTexture(data->ren,
		SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, WIDTH, HEIGHT)))
		ft_error(3);
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		ft_error(3);
	DIR_X = -1.0;
	DIR_Y = 0.0;
	PLAN_X = 0.0;
	PLAN_Y = 0.66;
	data->nb_weapon = 1;
	data->max_box = 7;
	data->speed = 0.06;
	data->key_floor = 1;
	data->for_exit = 1;
	data->nb_screen = 0;
	data->level = 0;
	data->lvl_height = 0;
	load_media(data);
}

void	ft_read(t_data *data)
{
	char	**reading;
	int		q;

	q = 0;
	reading = open_read(data);
	first_ar(data, reading);
	check_str(data, reading);
	int_malloc(data);
	make_arr(data, reading);
	while (reading[q])
	{
		free(reading[q]);
		q++;
	}
	free(reading);
}

void	game(t_data *data)
{
	if (data->for_exit == 0)
		while (data->for_exit == 0)
		{
			SDL_UpdateTexture(data->screen, NULL, data->buf, WIDTH << 2);
			SDL_RenderCopy(data->ren, data->screen, NULL, NULL);
			SDL_RenderPresent(data->ren);
			int i = -1;
			while (++i != HEIGHT)
			{
				int x = -1;
				while(++x != WIDTH)
				{
					data->buf[i][x] = 0;
				}
			}
			raycasting(data);
			door(data);
			key_event(data);
			if (data->key_floor != 3)
				skybox(data);
		}
	if (data->for_exit == 1)
		while (data->for_exit == 1)
			start_screen(data);
}

int		main(int argc, char *argv[])
{
	t_data *data;

	if (argc == 2)
	{
		if (!(data = (t_data *)malloc(sizeof(t_data))))
			ft_error(1);
		data->name = argv[1];
		data->fd = open(data->name, O_DIRECTORY);
		if (data->fd >= 0)
			ft_error(1);
		ft_read(data);
		init_all(data);
		game(data);
		fresh(data);
	}
	else
		ft_error(1);
	return (0);
}
