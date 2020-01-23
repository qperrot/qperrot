/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:47:47 by qperrot-          #+#    #+#             */
/*   Updated: 2020/01/23 14:13:08 by qperrot-         ###   ########.fr       */
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

int		ft_color(data_t *data, int x, int y)
{
	int		color;
	int		rgb;

	color = (int)(data->img.data[(data->win_width) *
										(data->win_height - x - 1) + (y)]);
	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
	return (rgb);
}

void	ft_screen_shot(data_t *data, int file, int pad)
{
	int				x;
	int				y;
	unsigned char	c[3];
	int				rgb;

	x = -1;
	ft_bzero(c, 3);
	while (++x < data->win_height)
	{
		y = -1;
		while (++y < data->win_width)
		{
			rgb = ft_color(data, x, y);
			if (write(file, &rgb, 3) < 0)
			{
				printf("ERROR WRITE COLORS\n");
				exit(0);
			}
		}
		if (pad < 0 && write(file, &c, pad) < 0)
		{
			printf("ERROR WRITE COLORS\n");
			exit(0);
		}
	}
}

void	ft_init_bmp(data_t *data, unsigned char *bmpfileheader, int filesize)
{
	int		i;

	i = -1;
	while (++i < 54)
		bmpfileheader[i] = (unsigned char)(0);
	bmpfileheader[0] = (unsigned char)('B');
	bmpfileheader[1] = (unsigned char)('M');
	bmpfileheader[2] = (unsigned char)(filesize);
	bmpfileheader[3] = (unsigned char)(filesize >> 8);
	bmpfileheader[4] = (unsigned char)(filesize >> 16);
	bmpfileheader[5] = (unsigned char)(filesize >> 24);
	bmpfileheader[10] = (unsigned char)(54);
	bmpfileheader[14] = (unsigned char)(40);
	bmpfileheader[18] = (unsigned char)(data->win_width);
	bmpfileheader[19] = (unsigned char)(data->win_width >> 8);
	bmpfileheader[20] = (unsigned char)(data->win_width >> 16);
	bmpfileheader[21] = (unsigned char)(data->win_width >> 24);
	bmpfileheader[22] = (unsigned char)(data->win_height);
	bmpfileheader[23] = (unsigned char)(data->win_height >> 8);
	bmpfileheader[24] = (unsigned char)(data->win_height >> 16);
	bmpfileheader[25] = (unsigned char)(data->win_height >> 24);
	bmpfileheader[26] = (unsigned char)(1);
	bmpfileheader[28] = (unsigned char)(24);
}

void	ft_save(data_t *data)
{
	int				pad;
	int				filesize;
	unsigned char	bmpfileheader[54];
	int				file;

	pad = (4 - ((3 * data->win_width) % 4)) % 4;
	filesize = 54 + (3 * data->win_width + pad) * data->win_height;
	ft_init_bmp(data, bmpfileheader, filesize);
	if ((file = open("test.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND)) < 0)
	{
		printf("ERROR FILE\n");
		exit(0);
	}
	if (write(file, &bmpfileheader, 54) < 0)
	{
		printf("ERROR WRITE BMP\n");
		exit(0);
	}
	ft_screen_shot(data, file, pad);
}
