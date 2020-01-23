/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_dir_plan_play.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:30:47 by qperrot-          #+#    #+#             */
/*   Updated: 2020/01/23 13:59:57 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "mlx.h"
#include "keys.h"
#include "cub3d.h"
#include "get_next_line.h"

void	ft_find_player(data_t *data)
{
	int		x;
	int		y;

	x = -1;
	while (++x < data->num_of_line)
	{
		y = -1;
		while (++y < data->num_of_el)
		{
			if (data->map_n[x][y] == 3)
			{
				if (data->player == 0)
				{
					data->player = 1;
					data->posX = x + 0.5;
					data->posY = y + 0.5;
				}
				else
				{
					printf("ERROR TOO MANY PLAYERS\n");
					ft_error_exit(data);
				}
			}
		}
	}
}

void	ft_init_dir_plan(data_t *data, char c)
{
	if (c == 'N' || c == 'S')
	{
		data->dirX = 1.0;
		data->dirY = 0.0;
		data->PlanX = 0.0;
		data->PlanY = -0.66;
		if (c == 'N')
		{
			data->dirX = -1.0;
			data->PlanY = 0.66;
		}
	}
	else if (c == 'E' || c == 'W')
	{
		data->dirX = 0.0;
		data->dirY = 1.0;
		data->PlanX = 0.66;
		data->PlanY = 0.0;
		if (c == 'W')
		{
			data->dirY = -1.0;
			data->PlanX = -0.66;
		}
	}
}
