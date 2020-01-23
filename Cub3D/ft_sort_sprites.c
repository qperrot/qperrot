/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:32:32 by qperrot-          #+#    #+#             */
/*   Updated: 2020/01/23 13:47:59 by qperrot-         ###   ########.fr       */
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

void	ft_dist_sprit_player(data_t *data)
{
	int		i;

	i = 0;
	while (i < data->numSprites)
	{
		data->bufferSprites[i][2] = ((data->posX - data->bufferSprites[i][0]) *
									(data->posX - data->bufferSprites[i][0])) +
									((data->posY - data->bufferSprites[i][1]) *
									(data->posY - data->bufferSprites[i][1]));
		i++;
	}
	ft_sort_sprites(data);
}

void	ft_take_coord(data_t *data)
{
	int		i;
	int		x;
	int		y;

	x = 0;
	i = 0;
	while (x < data->num_of_line)
	{
		y = 0;
		while (y < data->num_of_el)
		{
			if (data->map_n[x][y] == 2)
			{
				data->bufferSprites[i][0] = x;
				data->bufferSprites[i][1] = y;
				data->bufferSprites[i][2] =
				((data->posX - x) * (data->posX - x))
				+ ((data->posY - y) * (data->posY - y));
				i++;
			}
			y++;
		}
		x++;
	}
	ft_sort_sprites(data);
}

// void	ft_count_sprites(data_t *data)
// {
// 	int		x;
// 	int		y;

// 	x = 0;
// 	while (x < data->num_of_line)
// 	{
// 		y = 0;
// 		while (y < data->num_of_el)
// 		{
// 			if (data->map_n[x][y] == 2)
// 				data->numSprites++;
// 			y++;
// 		}
// 		x++;
// 	}
// }

void	ft_take_coord_sprites(data_t *data)
{
	int		i;

	ft_count_sprites(data);
	ft_free_sprite(data);
	i = 0;
	if (!(data->bufferSprites =
	(int**)malloc(sizeof(int*) * (data->numSprites))))
	{
		printf("ERROR\n");
		ft_error_exit(data);
	}
	while (i < data->numSprites)
	{
		if (!(data->bufferSprites[i] = (int*)malloc(sizeof(int) * (3))))
		{
			printf("ERROR\n");
			ft_error_exit(data);
		}
		i++;
	}
	ft_take_coord(data);
}

void    ft_swap_buf(data_t *data, int i, int x)
{
    int		tmp[1][3];

	tmp[0][0] = data->bufferSprites[i][0];
	tmp[0][1] = data->bufferSprites[i][1];
	tmp[0][2] = data->bufferSprites[i][2];
	data->bufferSprites[i][0] = data->bufferSprites[x][0];
	data->bufferSprites[i][1] = data->bufferSprites[x][1];
	data->bufferSprites[i][2] = data->bufferSprites[x][2];
	data->bufferSprites[x][0] = tmp[0][0];
	data->bufferSprites[x][1] = tmp[0][1];
	data->bufferSprites[x][2] = tmp[0][2];
}

void	ft_sort_sprites(data_t *data)
{
	int		x;
	int		i;

	i = data->numSprites - 1;
	while (i > 0)
	{
		x = i - 1;
		while (x >= 0)
		{
			if (data->bufferSprites[i][2] > data->bufferSprites[x][2])
			{
                ft_swap_buf(data, i, x);
				i = data->numSprites;
				break ;
			}
			else
				x--;
		}
		i--;
	}
}