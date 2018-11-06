/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 16:40:24 by vomelchu          #+#    #+#             */
/*   Updated: 2018/08/20 16:40:26 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int 	clip(int hgt_draw)
{
	if (hgt_draw < 0)
		hgt_draw = 0;
	if (hgt_draw >= HEIGHT)
		hgt_draw = HEIGHT - 1;
	return (hgt_draw);
}

void	find_floorwall(t_data *data)
{
	if (SIDE == 0 && RAY_DIR_X > 0)
	{
		FLOOR_WALL_X = MAP_X;
		FLOOR_WALL_Y = MAP_Y + WALL_X;
	}
	else if (SIDE == 0 && RAY_DIR_X < 0)
	{
		FLOOR_WALL_X = MAP_X + 1.0;
		FLOOR_WALL_Y = MAP_Y + WALL_X;
	}
	else if (SIDE == 1 && RAY_DIR_Y > 0)
	{
		FLOOR_WALL_X = MAP_X + WALL_X;
		FLOOR_WALL_Y = MAP_Y;
	}
	else
	{
		FLOOR_WALL_X = MAP_X + WALL_X;
		FLOOR_WALL_Y = MAP_Y + 1.0;
	}
}

void	dr_floor(t_data *data)
{
	find_floorwall(data);
	DIST_PLAYER = 0.0;
	if (DRAW_END < 0)
		DRAW_END = HEIGHT;
	data->y = DRAW_END - 1;
	while (++data->y < HEIGHT)
	{
		CURR_DIST = HEIGHT / (2.0 * data->y - HEIGHT);
		data->raycast.weight = (CURR_DIST - DIST_PLAYER) /
			(PERP_WALL_DIST - DIST_PLAYER);
		CURRENT_FLOOR_X = data->raycast.weight * FLOOR_WALL_X +
			(1.0 - data->raycast.weight) * POS_X;
		CURRENT_FLOOR_Y = data->raycast.weight * FLOOR_WALL_Y +
			(1.0 - data->raycast.weight) * POS_Y;
			if (data->level > 0)
		{
			if (data->array[data->level][(int)floor(CURRENT_FLOOR_Y)][(int)floor(CURRENT_FLOOR_X)] == 0)
				break;
		}
		FLOOR_TEX_X = (int)(CURRENT_FLOOR_X * 256) % 256;
		FLOOR_TEX_Y = (int)(CURRENT_FLOOR_Y * 256) % 256;
		if (data->key_floor != 2 && data->key_floor != 4 && data->buf[data->y][data->x] == 0)
			data->buf[data->y][data->x] = 0xf0f8ff;	
			/*data->buf[data->y][data->x] = get_pixel_int(data->floor,
				FLOOR_TEX_X, FLOOR_TEX_Y);*/
		if (data->key_floor != 1 && data->key_floor != 4 && data->buf[WIDTH / 4 * 3 - data->y][data->x] == 0)
			data->buf[WIDTH / 4 * 3 - data->y][data->x] =
		get_pixel_int(data->up, FLOOR_TEX_X, FLOOR_TEX_Y);
		/*if (data->buf[data->y][data->x] == 0)
			data->buf[data->y][data->x] = 0xf0f8ff;*/
	}
}

void	draw_wall(t_data *data)
{
	int n;
	int color;
	int tmp;

	n = data->array[data->level][MAP_Y][MAP_X] - 1;
	if (SIDE == 0)
		WALL_X = POS_Y + PERP_WALL_DIST * RAY_DIR_Y;
	else
		WALL_X = POS_X + PERP_WALL_DIST * RAY_DIR_X;
	WALL_X -= floor(WALL_X);
	TEX_X = (int)(WALL_X * 256.0);
	if (SIDE == 0 && RAY_DIR_X > 0)
		TEX_X = 256.0 - TEX_X - 1;
	if (SIDE == 1 & RAY_DIR_Y < 0)
		TEX_X = 256.0 - TEX_X - 1;
	data->y = DRAW_START - 1;
	while (++data->y < DRAW_END)
	{
		if (data->lvl_height > data->level)
			tmp = clip(data->y + ((data->lvl_height - data->level) * LINE_HEIGHT - 1));
		else if (data->lvl_height > data->level)
			tmp = data->y;
		else	
			tmp = clip(data->y - ((data->level - data->lvl_height)* LINE_HEIGHT - 1));
		if (data->buf[tmp][data->x] != 0)
			continue;
		data->d = data->y * 256 - HEIGHT * 128 + LINE_HEIGHT * 128;
		TEX_Y = ((data->d * 256.0) / LINE_HEIGHT / 256);
		if ((color = get_pixel_int(data->wall[n], TEX_X, TEX_Y)) != 0)
			data->buf[tmp][data->x] = color;
	}
}

/*void	draw_wall(t_data *data)
{
	int n;
	int color;

	n = data->array[data->level][MAP_Y][MAP_X] - 1;
	if (SIDE == 0)
		WALL_X = POS_Y + PERP_WALL_DIST * RAY_DIR_Y;
	else
		WALL_X = POS_X + PERP_WALL_DIST * RAY_DIR_X;
	WALL_X -= floor(WALL_X);
	TEX_X = (int)(WALL_X * 256.0);
	if (SIDE == 0 && RAY_DIR_X > 0)
		TEX_X = 256.0 - TEX_X - 1;
	if (SIDE == 1 & RAY_DIR_Y < 0)
		TEX_X = 256.0 - TEX_X - 1;
	int tmp1 = clip(DRAW_END - ((LINE_HEIGHT - 1) * data->level) + data->lvl_height);
	data->y = clip(DRAW_START - ((LINE_HEIGHT - 1) * data->level) + data->lvl_height);
		while (++data->y < tmp1)
		{
			data->d = data->y * 256 - HEIGHT * 128 + LINE_HEIGHT * 128;
			TEX_Y = ((data->d * 256.0) / LINE_HEIGHT / 256);
			if (TEX_Y < 0)
				TEX_Y = 0 - TEX_Y;
			if ((color = get_pixel_int(data->wall[n], TEX_X, TEX_Y)) != 0 && data->buf[data->y][data->x] == 0)
				data->buf[data->y][data->x] = color;
		}
}*/
