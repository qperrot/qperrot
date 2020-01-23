/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_wall_text.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 08:47:09 by qperrot-          #+#    #+#             */
/*   Updated: 2020/01/23 14:12:31 by qperrot-         ###   ########.fr       */
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

int		ft_find_color(data_t *data, int *texy, int *texx)
{
	int		color;

	if (data->side == 0 && data->rayDirX > 0)
		color = data->text[NORTH].data
				[data->text[NORTH].width * texy[NORTH] + texx[NORTH]];
	else if (data->side == 0 && data->rayDirX < 0)
		color = data->text[SOUTH].data
				[data->text[SOUTH].width * texy[SOUTH] + texx[SOUTH]];
	else if (data->side == 1 && data->rayDirY > 0)
		color = data->text[EAST].data
				[data->text[EAST].width * texy[EAST] + texx[EAST]];
	else
		color = data->text[WEST].data
				[data->text[WEST].width * texy[WEST] + texx[WEST]];
	return (color);
}

void	ft_draw_column(data_t *data, int *texx)
{
	int		y;
	int		d;
	int		texy[5];
	int		color;
	int		i;

	y = data->drawStart;
	while (y < data->drawEnd)
	{
		i = 0;
		d = y * 256 - data->win_height * 128 + data->lineHeight * 128;
		while (i < 5)
		{
			texy[i] = ((d * data->text[i].height) / data->lineHeight) / 256;
			i++;
		}
		color = ft_find_color(data, texy, texx);
		data->img.data[y * data->win_width + data->x] = color;
		y++;
	}
	data->Zbuffer[data->x] = data->perpWallDist;
	ft_floor_ceil_orient(data);
}

void	ft_put_wall_text(data_t *data)
{
	int		texx[5];
	int		i;

	i = 0;
	if (data->side == 0)
		data->wallX = data->posY + data->perpWallDist * data->rayDirY;
	else
		data->wallX = data->posX + data->perpWallDist * data->rayDirX;
	data->wallX -= floor((data->wallX));
	while (i < 5)
	{
		texx[i] = (int)(data->wallX * (double)data->text[i].width);
		if (data->side == 0 && data->rayDirX > 0)
			texx[i] = data->text[i].width - texx[i] - 1;
		if (data->side == 1 && data->rayDirY < 0)
			texx[i] = data->text[i].width - texx[i] - 1;
		i++;
	}
	ft_draw_column(data, texx);
}
