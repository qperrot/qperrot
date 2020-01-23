/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouve_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 10:01:48 by qperrot-          #+#    #+#             */
/*   Updated: 2020/01/23 14:02:15 by qperrot-         ###   ########.fr       */
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

void	ft_rotation(data_t *data, double speed)
{
	double	olddirx;
	double	oldplanex;

	if (data->k[KEY_RIGHT] != 0)
	{
		olddirx = data->dirX;
		data->dirX = data->dirX * cos(-speed) - data->dirY * sin(-speed);
		data->dirY = olddirx * sin(-speed) + data->dirY * cos(-speed);
		oldplanex = data->PlanX;
		data->PlanX = data->PlanX * cos(-speed) - data->PlanY * sin(-speed);
		data->PlanY = oldplanex * sin(-speed) + data->PlanY * cos(-speed);
	}
	if (data->k[KEY_LEFT] != 0)
	{
		olddirx = data->dirX;
		data->dirX = data->dirX * cos(speed) - data->dirY * sin(speed);
		data->dirY = olddirx * sin(speed) + data->dirY * cos(speed);
		oldplanex = data->PlanX;
		data->PlanX = data->PlanX * cos(speed) - data->PlanY * sin(speed);
		data->PlanY = oldplanex * sin(speed) + data->PlanY * cos(speed);
	}
}

void	ft_mouve_left_right(data_t *data, double movespeed, double security)
{
	if (data->k[KEY_A] != 0)
	{
		if (data->map_n[(int)(data->posX - data->PlanX * security)]
			[(int)data->posY] != WALL)
			data->posX -= data->PlanX * movespeed;
		if (data->map_n[(int)data->posX]
			[(int)(data->posY - data->PlanY * security)] != WALL)
			data->posY -= data->PlanY * movespeed;
	}
	if (data->k[KEY_D] != 0)
	{
		if (data->map_n[(int)(data->posX + data->PlanX * security)]
			[(int)data->posY] != WALL)
			data->posX += data->PlanX * movespeed;
		if (data->map_n[(int)data->posX]
			[(int)(data->posY + data->PlanY * security)] != WALL)
			data->posY += data->PlanY * movespeed;
	}
}

void	ft_mouve_up_down(data_t *data, double movespeed, double security)
{
	if (data->k[KEY_UP] != 0 || data->k[KEY_W] != 0)
	{
		if (data->map_n[(int)(data->posX + data->dirX * security)]
			[(int)data->posY] != WALL)
			data->posX += data->dirX * movespeed;
		if (data->map_n[(int)data->posX]
			[(int)(data->posY + data->dirY * security)] != WALL)
			data->posY += data->dirY * movespeed;
	}
	if (data->k[KEY_DOWN] != 0 || data->k[KEY_S] != 0)
	{
		if (data->map_n[(int)(data->posX - data->dirX * security)]
			[(int)data->posY] != WALL)
			data->posX -= data->dirX * movespeed;
		if (data->map_n[(int)data->posX]
			[(int)(data->posY - data->dirY * security)] != WALL)
			data->posY -= data->dirY * movespeed;
	}
	ft_mouve_left_right(data, movespeed, security);
}
