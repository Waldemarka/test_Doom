/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fresh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 16:33:36 by vomelchu          #+#    #+#             */
/*   Updated: 2018/09/14 16:33:38 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	other_fresh(t_data *data)
{
	int q;

	q = -1;
	while (++q != 3)
		Mix_FreeMusic(data->mus[q]);
	q = -1;
	while (++q != 2)
		Mix_FreeMusic(data->shots[q]);
	SDL_DestroyTexture(data->screen);
	SDL_DestroyRenderer(data->ren);
	SDL_DestroyWindow(data->win);
	SDL_Quit();
}

void	fresh(t_data *data)
{
	int q;

	q = -1;
	while (++q != 13)
		SDL_FreeSurface(data->wall[q]);
	q = -1;
	while (++q != 4)
		SDL_FreeSurface(data->start_screen[q]);
	q = -1;
	while (++q != 3)
		SDL_FreeSurface(data->pist[q]);
	q = -1;
	while (++q != 7)
		SDL_FreeSurface(data->drob[q]);
	q = -1;
	while (++q != 3)
		SDL_FreeSurface(data->sky[q]);
	SDL_FreeSurface(data->up);
	SDL_FreeSurface(data->floor);
	other_fresh(data);
}
