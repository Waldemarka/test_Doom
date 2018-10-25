/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 16:19:17 by vomelchu          #+#    #+#             */
/*   Updated: 2018/09/14 16:19:21 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	chek_door(t_data *data)
{
	if (data->door_cen == 1 &&
		(data->array[0][MAP_Y][MAP_X] == 5) &&
		((data->array[0][MAP_Y + 1][MAP_X] > 0 &&
		data->array[0][MAP_Y - 1][MAP_X] > 0) ||
		(data->array[0][MAP_Y][MAP_X + 1] > 0 &&
		data->array[0][MAP_Y][MAP_X - 1] > 0)) &&
		PERP_WALL_DIST < 2.5)
	{
		data->key_door = 1;
		data->dr_map_x = MAP_X;
		data->dr_map_y = MAP_Y;
	} 
	data->door_cen = 0;
}

void	door(t_data *data)
{
	data->time_door = SDL_GetTicks();
	if (data->key_door == 1)
	{
		if (data->time_door <= data->start_time_door + (150 * (data->q_door)))
		{
			data->max_box += data->q_door;
			raycasting(data);
		}
		if (data->time_door >= data->start_time_door + (150 * (data->q_door)))
		{
			data->max_box += data->q_door;
			raycasting(data);
			data->array[0][data->dr_map_y][data->dr_map_x] += 1;
			data->q_door++;
		}
		if (data->q_door > 8)
		{
			data->q_door = 0;
			data->key_door = 0;
			data->array[0][data->dr_map_y][data->dr_map_x] = 0;
			data->door_cen = 0;
		}
	}
	data->max_box = 6;
}
