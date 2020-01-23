/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor_ceil.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 08:56:32 by qperrot-          #+#    #+#             */
/*   Updated: 2020/01/23 13:58:54 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include "mlx.h"
#include "keys.h"
#include "cub3d.h"

void	ft_put_text_floor_ceil(data_t *data, int y, int color, double current_d)
{
	// double	weight;
	// double	currentfloorx;
	// double	currentfloory;
	// int		floortexx;
	// int		floortexy;
	color = 0;
	current_d = 0;
	//current_d = (data->win_height / (2.0 * y - data->win_height));//distance
	// weight = (current_d) / (data->perpWallDist);//coefficiaent
	// currentfloorx = (weight * data->floorXWall +
	// 					(1.0 - weight) * data->posX);//Position sur X
	// currentfloory = (weight * data->floorYWall +
	// 					(1.0 - weight) * data->posY);//Position sur Y
	// floortexx = (int)(currentfloorx * data->texWidth2)
	// 					% data->texWidth2;//Position Texel sur X
	// floortexy = (int)(currentfloory * data->texHeight2)
	// 					% data->texHeight2;//Position Texel sur Y
	//color = data->text[FLOOR].data[data->texWidth2 * floortexy + floortexx];
	data->img.data[y * data->win_width + data->x] = data->color_floor;
	//data->buffer[y][data->x] = data->color_floor;
	//color = data->text[CEIL].data[data->texWidth * floortexy + floortexx];
	data->img.data[data->win_width * (data->win_height - y - 1) + data->x] =
	data->color_ceil;
	//data->buffer[data->win_height - y - 1][data->x] = data->color_ceil;
}

void	ft_draw_floor_ceil(data_t *data)
{
	int		y;
	int		color;
	double	current_d;


	if (data->drawEnd < 0)
		data->drawEnd = data->win_height;
	current_d = 0.0;
	y = data->drawEnd;
	color = 0;
	while (y < data->win_height)
	{
		ft_put_text_floor_ceil(data, y, color, current_d);
		y++;
	}
}

void	ft_floor_ceil_orient(data_t *data)
{
	if (data->side == 0 && data->rayDirX > 0)
	{
		data->floorXWall = data->mapX;
		data->floorYWall = data->mapY + data->wallX;
	}
	else if (data->side == 0 && data->rayDirX < 0)
	{
		data->floorXWall = data->mapX + 1.0;
		data->floorYWall = data->mapY + data->wallX;
	}
	else if (data->side == 1 && data->rayDirY > 0)
	{
		data->floorXWall = data->mapX + data->wallX;
		data->floorYWall = data->mapY;
	}
	else
	{
		data->floorXWall = data->mapX + data->wallX;
		data->floorYWall = data->mapY + 1.0;
	}
	ft_draw_floor_ceil(data);
}
