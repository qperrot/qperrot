/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:19:03 by qperrot-          #+#    #+#             */
/*   Updated: 2020/01/23 16:26:49 by qperrot-         ###   ########.fr       */
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

void	ft_count_sprites(data_t *data)
{
	int		x;
	int		y;

	x = 0;
	while (x < data->num_of_line)
	{
		y = 0;
		while (y < data->num_of_el)
		{
			if (data->map_n[x][y] == 2)
				data->numSprites++;
			y++;
		}
		x++;
	}
}

void	print_map(data_t *data)
{
	double	camera_x;

	if (!(data->Zbuffer = (int*)malloc(sizeof(int) * (data->win_width))))
	{
		printf("ERROR\n");
		ft_error_exit(data);
	}
	//ft_init_img(data);
	data->x = 0;
	while (data->x < data->win_width)
	{
		camera_x = 2 * data->x / (double)data->win_width - 1;
		data->rayDirX = data->dirX + data->PlanX * camera_x;
		data->rayDirY = data->dirY + data->PlanY * camera_x;
		data->mapX = (int)data->posX;
		data->mapY = (int)data->posY;
		data->deltaDistX = fabs(1 / data->rayDirX);
		data->deltaDistY = fabs(1 / data->rayDirY);
		ft_sidedist(data);
		data->x++;
	}
	ft_init_sprite(data);
	if (data->save == 1)
		ft_save(data);
	data->save = 0;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.ptr, 0, 0);
}

int		main(int argc, char *argv[])
{
	data_t	data;
	pars_t	pars;

	data.save = 0;
	ft_check_arg(&pars, &data, argc, argv);
	if ((data.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data.mlx_win =
		mlx_new_window(data.mlx_ptr, data.win_width, data.win_height, "Cub3d"))
		== NULL)
		return (EXIT_FAILURE);
	ft_bzero(data.k, 280);
	data.Zbuffer = NULL;
	data.bufferSprites = NULL;
	ft_take_coord_sprites(&data);
	ft_sort_sprites(&data);
	ft_init_img(&data);
	print_map(&data);
	mlx_hook(data.mlx_win, 2, (1L << 0), key_press_hook, &data);
	mlx_hook(data.mlx_win, 3, (1L << 1), key_release_hook, &data);
	//mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img.ptr, 0, 0);
	mlx_loop_hook(data.mlx_ptr, deal_key, &data);
	mlx_loop(data.mlx_ptr);
	return (EXIT_FAILURE);
}
