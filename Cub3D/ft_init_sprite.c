/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 09:08:51 by qperrot-          #+#    #+#             */
/*   Updated: 2020/01/23 16:51:56 by qperrot-         ###   ########.fr       */
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
#define EMPTY 0
#define WALL 1

void	ft_draw_sprite(data_t *data, int texx, int y)
{
	int		d;
	int		texy;
	int		color;

	while (y < data->sprite.drawEndY)
	{
		d = (y - data->sprite.Vmouv) * 256 - data->win_height * 128
				+ data->sprite.height * 128;
		texy = ((d * data->text[SPRITE].height) / data->sprite.height) / 256;
		color = data->text[SPRITE].data[data->text[SPRITE].width * texy + texx];
		if ((color & 0x00FFFFFF) != 0)
			data->img.data[y * data->win_width + data->sprite.stripe] = color;
		y++;
	}
}

void	ft_check_drawend_drawstart(data_t *data)
{
	if (data->sprite.drawStartY < 0)
		data->sprite.drawStartY = 0;
	if (data->sprite.drawEndY >= data->win_height)
		data->sprite.drawEndY = data->win_height - 1;
	if (data->sprite.drawStartX < 0)
		data->sprite.drawStartX = 0;
	if (data->sprite.drawEndX >= data->win_width)
		data->sprite.drawEndX = data->win_width - 1;
}

void	ft_creat_sprite(data_t *data, int i)
{
	data->sprite.x = data->bufferSprites[i][0] + 0.5 - data->posX;
	data->sprite.y = data->bufferSprites[i][1] + 0.5 - data->posY;
	data->sprite.invDet = 1.0 /
						(data->PlanX * data->dirY - data->dirX * data->PlanY);
	data->sprite.tranfX = data->sprite.invDet *
	(data->dirY * data->sprite.x - data->dirX * data->sprite.y);
	data->sprite.tranfY = data->sprite.invDet *
	(-data->PlanY * data->sprite.x + data->PlanX * data->sprite.y);
	data->sprite.Vmouv = (int)(100 / data->sprite.tranfY);
	data->sprite.screenX = (int)((data->win_width / 2) *
	(1 + data->sprite.tranfX / data->sprite.tranfY));
	data->sprite.height = abs((int)(data->win_height /
							data->sprite.tranfY)) / 2;
	data->sprite.drawStartY = -data->sprite.height / 2 +
							data->win_height / 2 + data->sprite.Vmouv;
	data->sprite.drawEndY = data->sprite.height / 2 +
						data->win_height / 2 + data->sprite.Vmouv;
	data->sprite.width = abs((int)(data->win_height
								/ data->sprite.tranfY)) / 2;
	data->sprite.drawStartX = -data->sprite.width
								/ 2 + data->sprite.screenX;
	data->sprite.drawEndX = data->sprite.width
							/ 2 + data->sprite.screenX;
	ft_check_drawend_drawstart(data);
}

void	ft_init_sprite(data_t *data)
{
	int	i;
	int	y;
	int	texx;

	i = 0;
	while (i < data->numSprites)
	{
		ft_creat_sprite(data, i);
		data->sprite.stripe = data->sprite.drawStartX;
		while (data->sprite.stripe < data->sprite.drawEndX)
		{
			texx = (int)(256 * (data->sprite.stripe - (-data->sprite.width
					/ 2 + data->sprite.screenX)) *
					data->text[SPRITE].width / data->sprite.width) / 256;
			y = data->sprite.drawStartY;
			if (data->sprite.tranfY > 0 && data->sprite.stripe > 0 &&
				data->sprite.stripe < data->win_width &&
				data->sprite.tranfY <= data->Zbuffer[data->sprite.stripe] + 0.7)
				ft_draw_sprite(data, texx, y);
			data->sprite.stripe++;
		}
		i++;
	}
}
