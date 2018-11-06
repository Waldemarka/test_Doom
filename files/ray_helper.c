/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 10:31:56 by vomelchu          #+#    #+#             */
/*   Updated: 2018/11/01 10:31:58 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	make_level_floor(t_data *data)
{
	if (data->lvl_height == 0)
		dr_floor(data);
	/*if (data->level > 0)
		{
			if (data->array[data->level][(int)floor(CURRENT_FLOOR_Y)][(int)floor(CURRENT_FLOOR_X)] == 0)
				break;
		}*/
}

void	draw_level(t_data *data)
{
/*	data->level = 0;
	if (data->lvl_height == 0)
		while (data->level != data->nb_level && data->lvl_height == 0)
		{
			first_part_ray(data);
			data->level++;
		}
	else
	{*/
		data->level = data->lvl_height;
		first_part_ray(data);
		while (++data->level != data->nb_level)
			first_part_ray(data);
		data->level = data->lvl_height;
		while (--data->level >= 0)
			first_part_ray(data);
	//}
}