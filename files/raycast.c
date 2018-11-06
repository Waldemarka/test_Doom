/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 16:06:33 by vomelchu          #+#    #+#             */
/*   Updated: 2018/08/19 16:06:35 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	calculate_drawing(t_data *data)
{
	if (SIDE == 0)
		PERP_WALL_DIST = (MAP_X - POS_X + (1 - STEP_X)
			/ 2) / RAY_DIR_X;
	else
		PERP_WALL_DIST = (MAP_Y - POS_Y + (1 - STEP_Y)
			/ 2) / RAY_DIR_Y;
	LINE_HEIGHT = (int)(HEIGHT / PERP_WALL_DIST);
	DRAW_START = -LINE_HEIGHT / 2 + HEIGHT / 2;
	if (DRAW_START < 0)
		DRAW_START = 0;
	DRAW_END = LINE_HEIGHT / 2 + HEIGHT / 2;
	if (DRAW_END >= HEIGHT)
		DRAW_END = HEIGHT - 1;
	draw_wall(data);
	make_level_floor(data);
}

void	second_part_ray(t_data *data)
{
	if (RAY_DIR_X < 0)
	{
		STEP_X = -1;
		SIDE_DIST_X = (POS_X - MAP_X) * DELTA_DIST_X;
	}
	else
	{
		STEP_X = 1;
		SIDE_DIST_X = (MAP_X + 1.0 - POS_X)
		* DELTA_DIST_X;
	}
	if (RAY_DIR_Y < 0)
	{
		STEP_Y = -1;
		SIDE_DIST_Y = (POS_Y - MAP_Y) * DELTA_DIST_Y;
	}
	else
	{
		STEP_Y = 1;
		SIDE_DIST_Y = (MAP_Y + 1.0 - POS_Y) * DELTA_DIST_Y;
	}
}

void	dda_ray(t_data *data)
{
	while (HIT == 0)
	{
		if (SIDE_DIST_X < SIDE_DIST_Y)
		{
			SIDE_DIST_X += DELTA_DIST_X;
			MAP_X += STEP_X;
			SIDE = 0;
		}
		else
		{
			SIDE_DIST_Y += DELTA_DIST_Y;
			MAP_Y += STEP_Y;
			SIDE = 1;
		}
		if (data->array[data->level][MAP_Y][MAP_X] > 0
			&& data->lvl_height == data->level)
		{
			HIT = 1;
			calculate_drawing(data);
		}
		else if (data->lvl_height >= 0 &&
			data->array[data->level][MAP_Y][MAP_X] > 0 &&
			((MAP_Y <= data->height_arr - 1) && (MAP_Y >= 0) &&
		(MAP_X <= data->width_arr - 1) && (MAP_X >= 0)))
		{
			calculate_drawing(data);	
			if (data->array[data->level][MAP_Y][MAP_X] == 1 )
				HIT = 1;
		}
	
	}
}

void	first_part_ray(t_data *data)
{
	CAMER_X = (double)((data->x * 2) / (double)(WIDTH) - 1);
	RAY_DIR_X = DIR_X + PLAN_X * CAMER_X;
	RAY_DIR_Y = DIR_Y + PLAN_Y * CAMER_X;
	MAP_X = (int)POS_X;
	MAP_Y = (int)POS_Y;
	DELTA_DIST_X = fabs(1 / RAY_DIR_X);
	DELTA_DIST_Y = fabs(1 / RAY_DIR_Y);
	HIT = 0;
	second_part_ray(data);
	dda_ray(data);
}


void	raycasting(t_data *data)
{
	data->x = -1;
	static int nit;
	static int nit1;
	while (++data->x < WIDTH)
		draw_level(data);
	//printf("%f------%f\n", POS_X, POS_Y);
	data->che = SDL_GetTicks();
	if (data->che > 1000 * nit1)
	{
		printf("FPS : %d\n", nit);
		nit = 0;
		nit1++;
	}
	nit++;
	sprites(data);
}
