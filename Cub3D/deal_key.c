/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 10:19:39 by qperrot-          #+#    #+#             */
/*   Updated: 2020/01/23 18:06:40 by qperrot-         ###   ########.fr       */
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

void	ft_free_sprite(data_t *data)
{
	int		i;

	if (data->bufferSprites != NULL)
	{
		i = 0;
		while (i < data->numSprites)
		{
			free(data->bufferSprites[i]);
			i++;
		}
		free(data->bufferSprites);
		data->bufferSprites = NULL;
	}
	free(data->bufferSprites);
}

void	ft_free_buf(data_t *data)
{
	if (data->Zbuffer != NULL)
	{
		free(data->Zbuffer);
		data->Zbuffer = NULL;
	}
	free(data->Zbuffer);
}

void	ft_error_exit(data_t *data)
{
	ft_free_sprite(data);
	ft_free_buf(data);
	exit(0);
}

int		key_press_hook(int key, data_t *data)
{
	data->k[key] = 1;
	return (0);
}

int		key_release_hook(int key, data_t *data)
{
	data->k[key] = 0;
	return (0);
}

int		deal_key(data_t *data)
{
	double	movespeed;
	double	security;
	double	speed;
	// int		mouse;
	// int		x;
	// int		y;

	movespeed = 0.1;
	security = 0.5;
	speed = 0.1;
	//mouse = mlx_mouse_get_pos(data->mlx_win, &x, &y);
	//printf("x = %d et y = %d\n", x, y);
	if (data->k[KEY_ESC] != 0)
		ft_error_exit(data);
	if (data->k[KEY_RIGHT] != 0 || data->k[KEY_LEFT] != 0 ||
		data->k[KEY_A] != 0 || data->k[KEY_D] != 0 ||
		data->k[KEY_UP] != 0 || data->k[KEY_W] != 0 ||
		data->k[KEY_DOWN] != 0 || data->k[KEY_S] != 0)
	{
		//ft_mouve_up_down(data, movespeed, security);
		//ft_rotation(data, speed);
		mlx_destroy_image(data->mlx_ptr, data->img.ptr);
		data->img.ptr = mlx_new_image(data->mlx_ptr, data->win_width,
					data->win_height);
		data->img.data = (int *)mlx_get_data_addr(data->img.ptr, &data->img.bpp,
					&data->img.size_l, &data->img.endian);
		ft_free_buf(data);
		ft_mouve_up_down(data, movespeed, security);
		ft_rotation(data, speed);
		ft_dist_sprit_player(data);
		ft_sort_sprites(data);
		print_map(data);
		//mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.ptr, 0, 0);
	}
	return (0);
}
