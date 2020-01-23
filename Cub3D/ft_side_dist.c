/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_side_dist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:11:17 by qperrot-          #+#    #+#             */
/*   Updated: 2020/01/23 13:51:45 by qperrot-         ###   ########.fr       */
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

void	ft_draw_start_end(data_t *data)
{
	//Calculer la hauteur de la ligne a tracer
	data->lineHeight = (int)(data->win_height / data->perpWallDist);
	//Calcule des pixels max haut et max bas de la colonne a tracer
	data->drawStart = (-data->lineHeight / 2 + data->win_height / 2);
	data->drawEnd = (data->lineHeight / 2 + data->win_height / 2);
	//Limiter les zones de trace a l ecran uniquement
	if (data->drawStart < 0)
		data->drawStart = 0;
	if (data->drawEnd >= data->win_height)
		data->drawEnd = data->win_height - 1;
	ft_put_wall_text(data);
}

void	ft_per_wall(data_t *data)
{
	if (data->side == 0)
		data->perpWallDist = (data->mapX - data->posX + (1 - data->stepX) / 2)
							/ data->rayDirX;
	else
		data->perpWallDist = (data->mapY - data->posY + (1 - data->stepY) / 2)
							/ data->rayDirY;
	ft_draw_start_end(data);
}

void	ft_hit_wall(data_t *data)
{
	//Tant que le rayon ne rencontre pas le mur
	while (data->hit == 0)
	{
		//Passer a la case suivante sur X ou Y
		if (data->sideDistX < data->sideDistY)
		{
			data->sideDistX += data->deltaDistX;// Agrandis le rayon
			data->mapX += data->stepX;// Prochaine case ou case precedente sur X
			data->side = 0;// Orientation du mur
		}
		else
		{
			data->sideDistY += data->deltaDistY;// Agrandis le rayon
			data->mapY += data->stepY;// Prochaine case ou case precedente sur Y
			data->side = 1;// Orientation du mur
		}
		if (data->map_n[data->mapX][data->mapY] == 1)
			data->hit = 1;// Stop la boucle
	}
	ft_per_wall(data);
}

void	ft_sidedist(data_t *data)
{
	data->hit = 0;
	if (data->rayDirX < 0)
	{
		data->stepX = -1;// vecteur de direction
		data->sideDistX = (data->posX - data->mapX) * data->deltaDistX;
	}
	else
	{
		data->stepX = 1;
		data->sideDistX = (data->mapX + 1.0 - data->posX) * data->deltaDistX;
	}
	if (data->rayDirY < 0)
	{
		data->stepY = -1;// vecteur de direction
		data->sideDistY = (data->posY - data->mapY) * data->deltaDistY;
	}
	else
	{
		data->stepY = 1;
		data->sideDistY = (data->mapY + 1.0 - data->posY) * data->deltaDistY;
	}
	ft_hit_wall(data);
}
