/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:29:56 by qperrot-          #+#    #+#             */
/*   Updated: 2020/01/07 13:29:59 by qperrot-         ###   ########.fr       */
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
#define mapWidth 25
#define mapHeight 25
#define EMPTY 0
#define WALL 1

int	worldMap[mapWidth][mapHeight]= 
{		
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,0,1,1,1,1},
	{1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1},
	{1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,0,1},
	{1,1,0,0,0,0,0,0,1,1,0,1,0,1,0,1,1,1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,1,0,0,1},
	{1,1,0,0,0,0,0,0,1,1,0,1,0,1,0,1,1,1,1,1,0,1,1,1,1},
	{1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1},
	{1,1,1,1,0,1,1,1,1,1,1,1,0,0,1,0,1,1,0,0,0,0,0,0,1},
	{1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1,0,0,0,1,0,1},
	{1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,1},
	{1,1,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1},
	{1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,1,0,1,0,1,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,1,0,1,0,1,0,0,1},
	{1,1,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1},
	{1,1,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	print_map(data_t *data)
{
    // Position de la camera sur la map
    data->mapX = (int)data->posX;// Case sur laquelle se trouve la camera sur X (map[X][Y])
	data->mapY = (int)data->posY;// Case sur laquelle se trouve la camera sur Y

    // Center of the screen (not the map)
    data->CenterX = data->win_width / 2;
    data->CenterY = data->win_height / 2;

    // Champ de vision FOV (degre)
    data->Fov = 60 * M_PI / 180;

    // viewing angle or point of view
    data->ViewAng = 45 * M_PI / 180;

    // Distance between Camera and projection s angle
    data->DistCam = (data->win_width / 2) / tan(30 * (M_PI / 180));

    //Angle between each ray
    data->RayAng = (60 / data->win_width) * M_PI / 180;

    

}

int		main(void)
{
	data_t	data;
	data.win_width = 920;
	data.win_height = 580;
	data.posX = 22.0;
	data.posY = 11.5;
	data.dirX = -1.0;
	data.dirY = 0.0;
	data.PlanX = 0.0;
	data.PlanY = 0.66;
	data.spritX = 20.0;
	data.spritY = 10.0;
	ft_memcpy(data.map, worldMap, 25*25*sizeof(int));

	if ((data.mlx_ptr = mlx_init()) == NULL)
        	return (EXIT_FAILURE);
    if ((data.mlx_win = mlx_new_window(data.mlx_ptr, data.win_width, data.win_height, "Hello world")) == NULL)
        	return (EXIT_FAILURE);
	ft_bzero(data.k, 280);
	
	print_map(&data);
	//mlx_hook(data.mlx_win, 3, (1L << 1), key_release_hook, &data);
	mlx_hook(data.mlx_win, 2, (1L << 0), key_press_hook, &data);
	mlx_hook(data.mlx_win, 3, (1L << 1), key_release_hook, &data);
  	mlx_loop_hook(data.mlx_ptr, deal_key, &data);

	mlx_loop(data.mlx_ptr);
	return (EXIT_FAILURE);
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include "mlx.h"
#include "keys.h"
#include "cub3d.h"
#define mapWidth 25
#define mapHeight 25
#define EMPTY 0
#define WALL 1

void	ft_take_coord_sprites(data_t *data)
{
	int		x;
	int		y;
	int		i;
	int		tmp[1][3];

	i = 0;
	while (i < data->numSprites)
	{
		x = i + 1;
		while (x < data->numSprites)
		{
			if (data->bufferSprites[i][2] < data->bufferSprites[x][2])
			{
				tmp[0][0] = data->bufferSprites[i][0];
				tmp[0][1] = data->bufferSprites[i][1];
				tmp[0][2] = data->bufferSprites[i][2];
				data->bufferSprites[i][0] = data->bufferSprites[x][0];
				data->bufferSprites[i][1] = data->bufferSprites[x][1];
				data->bufferSprites[i][2] = data->bufferSprites[x][2];
				data->bufferSprites[x][0] = tmp[0][0];
				data->bufferSprites[x][1] = tmp[0][1];
				data->bufferSprites[x][2] = tmp[0][2];
				i = 0;
				break ;
			}
			else
				x++;
		}
		i++;
	}
}

int	worldMap[mapWidth][mapHeight]= 
{		
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,0,1,1,1,1},
	{1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1},
	{1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,0,1},
	{1,1,0,0,0,0,0,0,1,1,0,1,0,1,0,1,1,1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,1,0,0,1},
	{1,1,0,0,0,0,0,0,1,1,0,1,0,1,0,1,1,1,1,1,0,1,1,1,1},
	{1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1},
	{1,1,1,1,0,1,1,1,1,1,1,1,0,0,1,0,1,1,0,0,0,0,0,0,1},
	{1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1,0,0,0,1,0,1},
	{1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,1},
	{1,1,0,0,0,0,0,1,1,1,0,2,0,1,1,1,1,1,1,0,0,0,1,1,1},
	{1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,1,0,1,0,1,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,1,2,0,0,0,0,1,1,0,1,0,1,0,1,0,0,1},
	{1,1,0,0,0,0,0,1,1,2,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1},
	{1,1,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

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
	double	moveSpeed = 0.1;
	double	security = 0.5;
	double	rotspeed = 0.1;
	
	mlx_destroy_image(data->mlx_ptr, data->img.ptr);

	if (data->k[KEY_ESC] != 0)
        exit(0);
    if (data->k[KEY_A] != 0)
    {
        if (data->map[(int)(data->posX - data->PlanX  * security)][(int)data->posY] == EMPTY)
			data->posX -= data->PlanX * moveSpeed;
		if (data->map[(int)data->posX][(int)(data->posY - data->PlanY * security)] == EMPTY)
			data->posY -= data->PlanY * moveSpeed;
    }
    if (data->k[KEY_D] != 0)
    {
        if(data->map[(int)(data->posX + data->PlanX  * security)][(int)data->posY] == EMPTY)
			data->posX += data->PlanX * moveSpeed;
		if(data->map[(int)data->posX][(int)(data->posY + data->PlanY * security)] == EMPTY)
			data->posY += data->PlanY * moveSpeed;
    }
    if (data->k[KEY_UP] != 0 || data->k[KEY_W] != 0)
    {
        if(data->map[(int)(data->posX + data->dirX * security)][(int)data->posY] == EMPTY)
            data->posX += data->dirX * moveSpeed;
        if(data->map[(int)data->posX][(int)(data->posY + data->dirY * security)] == EMPTY)
            data->posY += data->dirY * moveSpeed;
    }
    if (data->k[KEY_DOWN] != 0 || data->k[KEY_S] != 0)
    {
        if(data->map[(int)(data->posX - data->dirX * security)][(int)data->posY] == EMPTY)
            data->posX -= data->dirX * moveSpeed;
        if(data->map[(int)data->posX][(int)(data->posY - data->dirY * security)] == EMPTY)
            data->posY -= data->dirY * moveSpeed;
    }
    if (data->k[KEY_RIGHT] != 0)
    {
        double oldDirX = data->dirX;
        data->dirX = data->dirX * cos(-rotspeed) - data->dirY * sin(-rotspeed);
        data->dirY = oldDirX * sin(-rotspeed) + data->dirY * cos(-rotspeed);
        double oldPlaneX = data->PlanX;
        data->PlanX = data->PlanX * cos(-rotspeed) - data->PlanY * sin(-rotspeed);
        data->PlanY = oldPlaneX * sin(-rotspeed) + data->PlanY * cos(-rotspeed);
    }
    if (data->k[KEY_LEFT] != 0)
    {
        double oldDirX = data->dirX;
        data->dirX = data->dirX * cos(rotspeed) - data->dirY * sin(rotspeed);
        data->dirY = oldDirX * sin(rotspeed) + data->dirY * cos(rotspeed);
        double oldPlaneX = data->PlanX;
        data->PlanX = data->PlanX * cos(rotspeed) - data->PlanY * sin(rotspeed);
        data->PlanY = oldPlaneX * sin(rotspeed) + data->PlanY * cos(rotspeed);
    }
	int		x = 0;
	int		y = 0;
	while (x < data->win_width)
	{
		data->Zbuffer[x] = 0;
		x++;
	}
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			data->buffer[y][x] = 0;
			x++;
		}
		y++;
	}

	// x = 0;
	// while (x < data->numSprites)
	// {
	// 	y = 0;
	// 	while (y < 3)
	// 	{
	// 		data->bufferSprites[x][y] = 0;
	// 		y++;
	// 	}
	// 	x++;
	// }
	// int		i;
	// int		tmp[1][3];

	// i = 0;
	// x = 0;
	// while (x < mapWidth)
	// {
	// 	y = 0;
	// 	while (y < mapHeight)
	// 	{
	// 		if (worldMap[x][y] == 2)
	// 		{
	// 			data->bufferSprites[i][0] = x;
	// 			data->bufferSprites[i][1] = y;
	// 			data->bufferSprites[i][2] = ((data->posX - x) * (data->posX - x)) + ((data->posY - y) * (data->posY - y));
	// 			i++;
	// 		}
	// 		y++;
	// 	}
	// 	x++;
	// }
	// data->numSprites = i;
	// i = 0;
	// while (i < data->numSprites)
	// {
	// 	x = i + 1;
	// 	while (x < data->numSprites)
	// 	{
	// 		if (data->bufferSprites[i][2] < data->bufferSprites[x][2])
	// 		{
	// 			tmp[0][0] = data->bufferSprites[i][0];
	// 			tmp[0][1] = data->bufferSprites[i][1];
	// 			tmp[0][2] = data->bufferSprites[i][2];
	// 			data->bufferSprites[i][0] = data->bufferSprites[x][0];
	// 			data->bufferSprites[i][1] = data->bufferSprites[x][1];
	// 			data->bufferSprites[i][2] = data->bufferSprites[x][2];
	// 			data->bufferSprites[x][0] = tmp[0][0];
	// 			data->bufferSprites[x][1] = tmp[0][1];
	// 			data->bufferSprites[x][2] = tmp[0][2];
	// 			i = 0;
	// 			break ;
	// 		}
	// 		else
	// 			x++;
	// 	}
	// 	i++;
	// }
	print_map(data);
	return (0);
}

// void	ft_take_coord_sprites(data_t *data)
// {
// 	int		x;
// 	int		y;
// 	int		i;
// 	int		tmp[1][3];

// 	i = data->numSprites - 1;
// 	x = 0;
// 	// while (x < mapWidth)
// 	// {
// 	// 	y = 0;
// 	// 	while (y < mapHeight)
// 	// 	{
// 	// 		if (worldMap[x][y] == 2)
// 	// 		{
// 	// 			data->bufferSprites[i][0] = x;
// 	// 			data->bufferSprites[i][1] = y;
// 	// 			data->bufferSprites[i][2] = ((data->posX - x) * (data->posX - x)) + ((data->posY - y) * (data->posY - y));
// 	// 			i++;
// 	// 		}
// 	// 		y++;
// 	// 	}
// 	// 	x++;
// 	// }
// 	data->bufferSprites[i][0] = data->spritX;
// 	data->bufferSprites[i][1] = data->spritY;
// 	data->bufferSprites[i][2] = ((data->posX - data->spritX) * (data->posX - data->spritX)) + ((data->posY - data->spritY) * (data->posY - data->spritY));
// 	//data->numSprites += 1;

// 	i = 0;
// 	while (i < data->numSprites)
// 	{
// 		x = i + 1;
// 		while (x < data->numSprites)
// 		{
// 			if (data->bufferSprites[i][2] < data->bufferSprites[x][2])
// 			{
// 				tmp[0][0] = data->bufferSprites[i][0];
// 				tmp[0][1] = data->bufferSprites[i][1];
// 				tmp[0][2] = data->bufferSprites[i][2];
// 				data->bufferSprites[i][0] = data->bufferSprites[x][0];
// 				data->bufferSprites[i][1] = data->bufferSprites[x][1];
// 				data->bufferSprites[i][2] = data->bufferSprites[x][2];
// 				data->bufferSprites[x][0] = tmp[0][0];
// 				data->bufferSprites[x][1] = tmp[0][1];
// 				data->bufferSprites[x][2] = tmp[0][2];
// 				i = 0;
// 				break ;
// 			}
// 			else
// 				x++;
// 		}
// 		i++;
// 	}
// }

// void	ft_draw_sprites(data_t *data, int texHeight3, int texWidth3)
// {
// 	if (data->hitSprite == 1)
// 	{
// 		data->hitSprite = 0;
// 		//printf("posY %f\n",data->posY);
// 		//printf("spritY %f\n",data->spritY);
// 		double	spriteX = data->spritX + 0.5 - data->posX;
// 		double	spriteY = data->spritY + 0.5 - data->posY;

// 		double	invDet = 1.0 / (data->PlanX * data->dirY - data->dirX * data->PlanY);

// 		double	tranformX = invDet * (data->dirY * spriteX - data->dirX * spriteY);
// 		double	tranformY = invDet * (-data->PlanY * spriteX + data->PlanX * spriteY);

// 		int		spriteScreenX = (int)((data->win_width / 2) * (1 + tranformX / tranformY));

// 		int		spriteHeight = abs((int)(data->win_height / tranformY));

// 		int		drawStartY = -spriteHeight / 2 + data->win_height / 2;

// 		if (drawStartY < 0)
// 			drawStartY = 0;

// 		int		drawEndY = spriteHeight / 2 + data->win_height / 2;

// 		if (drawEndY >= data->win_height)
// 			drawEndY = data->win_height - 1;

// 		int		spriteWidth = abs((int)(data->win_height / tranformY));

// 		int		drawStartX = -spriteWidth / 2 + spriteScreenX;

// 		if (drawStartX < 0)
// 			drawStartX = 0;

// 		int		drawEndX = spriteWidth / 2 + spriteScreenX;

// 		if (drawEndX >= data->win_width)
// 			drawEndX = data->win_width - 1;

// 		int		stripe = drawStartX;
		
// 		while (stripe < drawEndX)
// 		{
// 			int		texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * texWidth3 / spriteWidth) / 256;
// 			//printf("stripe %d\n", data->Zbuffer[stripe]);
// 			if (tranformY > 0 && stripe > 0 && stripe < data->win_width)
// 			{
// 				int		y = drawStartY;
// 				while (y < drawEndY)
// 				{
// 					int		d = (y) * 256 - data->win_height * 128 + spriteHeight * 128;
// 					int		texY = ((d * texHeight3) / spriteHeight) / 256;
// 					int		color = data->text7.data[texWidth3 * texY + texX];
// 					//printf("%d\n", color);
// 					if ((color & 0x00FFFFFF) != 0)
// 					{
// 						//data->img.data[y * data->win_width + data->x] = color;
// 						//data->img.data[data->win_width * (data->win_height - y - 1) + data->x] = color;
// 						data->img.data[y * data->win_width + stripe] = color;
// 						//buffer[y][stripe] = color;
// 						//data->img.data[y * data->win_width + data->x] = color;
// 						y++;
// 					}
// 					else
// 					{
// 						data->img.data[y * data->win_width + stripe] = data->buffer[y][stripe];
// 						//printf("jjj\n");
// 						y++;
// 					}
// 						//data->img.data[data->win_width * (data->win_height - y - 1) + data->x] = buffer[y][data->x];
// 					//y++;
// 				}
// 			}
// 			stripe++;
// 		}
// 	}
// 	return ;
// }

void	print_map(data_t *data)
{
	data->x = 0;
	int		texWidth = 512;
	int		texHeight = 512;	
	int		texWidth2 = 540;
	int		texHeight2 = 450;
	int		texWidth3 = 512;
	int		texHeight3 = 512;
	data->hitSprite = 0;
	//data->numSprites = 0;
	//int		buffer[data->win_height][data->win_width];
	//int		Zbuffer[data->win_width];

	data->img.ptr = mlx_new_image(data->mlx_ptr, data->win_width, data->win_height);
	data->img.data = (int *)mlx_get_data_addr(data->img.ptr, &data->img.bpp, &data->img.size_l, &data->img.endian);
	data->text1.ptr = mlx_xpm_file_to_image(data->mlx_ptr, "porte-shining5.xpm", &texWidth, &texHeight);
	data->text1.data = (int *)mlx_get_data_addr(data->text1.ptr, &data->text1.bpp, &data->text1.size_l, &data->text1.endian);
	data->text2.ptr = mlx_xpm_file_to_image(data->mlx_ptr, "mur-rouge.xpm", &texWidth, &texHeight);
	data->text2.data = (int *)mlx_get_data_addr(data->text2.ptr, &data->text2.bpp, &data->text2.size_l, &data->text2.endian);
	data->text3.ptr = mlx_xpm_file_to_image(data->mlx_ptr, "tapi-symb.xpm", &texWidth, &texHeight);
	data->text3.data = (int *)mlx_get_data_addr(data->text3.ptr, &data->text3.bpp, &data->text3.size_l, &data->text3.endian);
	data->text4.ptr = mlx_xpm_file_to_image(data->mlx_ptr, "tapi-symb.xpm", &texWidth, &texHeight);
	data->text4.data = (int *)mlx_get_data_addr(data->text4.ptr, &data->text4.bpp, &data->text4.size_l, &data->text4.endian);
	data->text5.ptr = mlx_xpm_file_to_image(data->mlx_ptr, "shining_sol.xpm", &texWidth2, &texHeight2);
	data->text5.data = (int *)mlx_get_data_addr(data->text5.ptr, &data->text5.bpp, &data->text5.size_l, &data->text5.endian);
	data->text6.ptr = mlx_xpm_file_to_image(data->mlx_ptr, "plafond-blanc.xpm", &texWidth, &texHeight);
	data->text6.data = (int *)mlx_get_data_addr(data->text6.ptr, &data->text6.bpp, &data->text6.size_l, &data->text6.endian);
	data->text7.ptr = mlx_xpm_file_to_image(data->mlx_ptr, "banana2.xpm", &texWidth3, &texHeight3);
	data->text7.data = (int *)mlx_get_data_addr(data->text7.ptr, &data->text7.bpp, &data->text7.size_l, &data->text7.endian);

	int		x = 0;
	int		y = 0;
	while (x < data->win_width)
	{
		data->Zbuffer[x] = 0;
		x++;
	}
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			data->buffer[y][x] = 0;
			x++;
		}
		y++;
	}

	while (data->x < data->win_width)
	{
		//position de depart et direction du rayon
		data->CameraX = 2 * data->x / (double)data->win_width - 1;// Position de la colonne par rapport au centre de l ecran
		//printf("posx : %f\n", data->CameraX);
		//double	rayPosX = data->posX;// Position de depart du rayon sur X
		//double	rayPosY = data->posY;// Position de depart du rayon sur Y
		data->rayDirX = data->dirX + data->PlanX * data->CameraX;// Direction du rayon sur X
		data->rayDirY = data->dirY + data->PlanY * data->CameraX;// Direction du rayon sur Y
		
		data->mapX = (int)data->posX;// Case sur laquelle se trouve la camera sur X (map[X][Y])
		data->mapY = (int)data->posY;// Case sur laquelle se trouve la camera sur Y

		//Longuer du rayon
		//double	sideDistX;
		//double	sideDistY;

		//Longueur du rayon entre chaque intersection
		data->deltaDistX = fabs(1 / data->rayDirX);
		data->deltaDistY = fabs(1 / data->rayDirY);
		
		//Direction du vecteur sur X et Y (-1 ou +1)
		//double	stepX;
		//double	stepY;
			
		data->hit = 0;// le rayon a t il touche un mur ?
		//data->hitSprite = 0;// le rayon a t il touche un Sprite ?
		//double	side;// Quelle oriantation a le mur dans la map (Nord Sud Est Ouest)
		
		//double	perpWallDist;// Distance du rayon corrigée
		
		//Calcule le vecteur de direction et la longueur entre deux segments
		if (data->rayDirX < 0)
		{
			data->stepX = -1;// vecteur de direction
			data->sideDistX = (data->posX - data->mapX) * data->deltaDistX;// Distance
		}
		else
		{
			data->stepX = 1;
			data->sideDistX = (data->mapX + 1.0 - data->posX) * data->deltaDistX;
		}
		if (data->rayDirY < 0)
		{
			data->stepY = -1;// vecteur de direction
			data->sideDistY = (data->posY - data->mapY) * data->deltaDistY;// Distance
		}
		else
		{
			data->stepY = 1;
			data->sideDistY = (data->mapY + 1.0 - data->posY) * data->deltaDistY;
		}
		// printf("posx : %f\n", data->posX);
		// printf("mapX : %d\n", data->mapX);
		// printf("deltaDistX : %f\n", data->deltaDistX);
		// printf("sideDistX : %f\n", data->sideDistX);
		// printf("posy : %f\n", data->posY);
		// printf("mapy : %d\n", data->mapY);
		// printf("deltaDisty : %f\n", data->deltaDistY);
		// printf("sideDisty : %f\n", data->sideDistY);
		// printf("rayDirX : %f\n", data->rayDirX);
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
			//Si le rayon rencontre un mur
			if (worldMap[data->mapX][data->mapY] == 2 && data->hitSprite == 0)
			{
				// data->spritX = data->mapX;
				// data->spritY = data->mapY;
				// data->numSprites += 1;
				// ft_take_coord_sprites(data);
				//data->spritX = data->mapX;
				//data->spritY = data->mapY;
				//printf("numSprites %d\n", data->numSprites);
				data->hitSprite = 1;
			}
			if (worldMap[data->mapX][data->mapY] == 1)
				data->hit = 1;// Stop la boucle
		}

		//Calcule la distance corrigée pour la projection
		if (data->side == 0)
			data->perpWallDist = (data->mapX - data->posX + (1 - data->stepX) / 2) / data->rayDirX;
		else
			data->perpWallDist = (data->mapY - data->posY + (1 - data->stepY) / 2) / data->rayDirY;
		
		// printf("perpWallDist : %f\n", data->perpWallDist);
		// printf("posx : %f\n", data->posX);
		// printf("mapX : %d\n", data->mapX);
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
		
		// if(data->drawEnd < data->drawStart) {data->drawStart += data->drawEnd; data->drawEnd = data->drawStart - data->drawEnd; data->drawStart -= data->drawEnd;} //swap drawStart and drawEnd
		// if(data->drawEnd < 0 || data->drawStart >= data->win_height  || data->x < 0 || data->x >= data->win_width) return ; //no single point of the line is on screen
		// if(data->drawStart < 0) data->drawStart = 0; //clip
		// if(data->drawEnd >= data->win_width) data->drawEnd = data->win_height - 1; //clip

		//PUT TEXTURE ON WALLS
		if (data->side == 0)
			data->wallX = data->posY + data->perpWallDist * data->rayDirY;
		else
			data->wallX = data->posX + data->perpWallDist * data->rayDirX;
		data->wallX -= floor((data->wallX));
		//printf("%f\n", data->wallX);

		int texX = (int)(data->wallX * (double)texWidth);
		if (data->side == 0 && data->rayDirX > 0)
			texX = texWidth - texX - 1;
		if (data->side == 1 && data->rayDirY < 0)
			texX = texWidth - texX - 1;

		//Tracer la colonne
		int	y = data->drawStart;

		while (y < data->drawEnd)
		{
			int d = y * 256 - data->win_height * 128 + data->lineHeight * 128;//256 and 128 factor to avoid floats
			int texY = ((d * texHeight) / data->lineHeight) / 256;
			int color;
			if (data->side == 0 && data->rayDirX > 0)//NORD
			{
				color = data->text1.data[texWidth * texY + texX];
			}
			else if (data->side == 0 && data->rayDirX < 0)//SUD
			{
				color = data->text2.data[texWidth * texY + texX];
			}
			else if (data->side == 1 && data->rayDirY > 0)//EST
			{
				color = data->text3.data[texWidth * texY + texX];
			}
			else//OUEST
			{
				color = data->text4.data[texWidth * texY + texX];
			}
			//int	color = data->text.data[texWidth * texY + texX];// Couleur du pixel pour un mur Nord/Sud
			// if (data->side == 1)
			// {
			// 	color = (color >> 1) & 8355711;
			// }
				//color = 0xA9A9A9;// Couleur du pixel pour un mur Est/Ouest
			//if (worldMap[data->mapX][data->mapY] == 1)
			data->img.data[y * data->win_width + data->x] = color;
			data->buffer[y][data->x] = color;
			y++;
		}
		data->Zbuffer[data->x] = data->perpWallDist;

		if (data->drawEnd < 0)
			data->drawEnd = data->win_height;
		
		//texturer le sol 
		data->distWall = data->perpWallDist;//Distance du mur
		//data->distPlayer = 0.0;//Distance de la camera
		data->currentDist = 0.0;//Point de depart de la texture
	
		//Le mur peut etre oriente de 4 facon differentes
		if (data->side == 0 && data->rayDirX > 0)//NORD
		{
			data->floorXWall = data->mapX;
			data->floorYWall = data->mapY + data->wallX;
		}
		else if (data->side == 0 && data->rayDirX < 0)//SUD
		{
			data->floorXWall = data->mapX + 1.0;
			data->floorYWall = data->mapY + data->wallX;
		}
		else if (data->side == 1 && data->rayDirY > 0)//EST
		{
			data->floorXWall = data->mapX + data->wallX;
			data->floorYWall = data->mapY;
		}
		else//OUEST
		{
			data->floorXWall = data->mapX + data->wallX;
			data->floorYWall = data->mapY + 1.0;
		}

		//Tracer le sol de la fin du mur au bas de l ecran
		y = data->drawEnd;
		while (y < data->win_height)
		{
			data->currentDist = (data->win_height / (2.0 * y - data->win_height));//distance
			data->weight = (data->currentDist) / (data->distWall);//coefficiaent
			data->currentfloorX = (data->weight * data->floorXWall + (1.0 - data->weight) * data->posX);//Position sur X
			data->currentfloorY = (data->weight * data->floorYWall + (1.0 - data->weight) * data->posY);//Position sur Y
			data->floortexX = (int)(data->currentfloorX * texWidth2) % texWidth2;//Position Texel sur X
			data->floortexY = (int)(data->currentfloorY * texHeight2) % texHeight2;//Position Texel sur Y
			int	color = data->text5.data[texWidth2 * data->floortexY + data->floortexX];
			// if (data->side == 1)
			// {
			// 	color = (color >> 1) & 8355711;
			// }
			//printf("%f\n", data->floortexX);
			data->img.data[y * data->win_width + data->x] = color;
			data->buffer[y][data->x] = color;
			//data->img.data[data->win_width * (data->win_height - y - 1) + data->x] = color;
			y++;
		}
		data->distWall = data->perpWallDist;//Distance du mur
		//data->distPlayer = 0.0;//Distance de la camera
		data->currentDist = 0.0;//Point de depart de la texture
		if (data->side == 0 && data->rayDirX > 0)//NORD
		{
			data->floorXWall = data->mapX;
			data->floorYWall = data->mapY + data->wallX;
		}
		else if (data->side == 0 && data->rayDirX < 0)//SUD
		{
			data->floorXWall = data->mapX + 1.0;
			data->floorYWall = data->mapY + data->wallX;
		}
		else if (data->side == 1 && data->rayDirY > 0)//EST
		{
			data->floorXWall = data->mapX + data->wallX;
			data->floorYWall = data->mapY;
		}
		else//OUEST
		{
			data->floorXWall = data->mapX + data->wallX;
			data->floorYWall = data->mapY + 1.0;
		}
		y = data->drawEnd;
		while (y < data->win_height)
		{
			data->currentDist = (data->win_height / (2.0 * y - data->win_height));//distance
			data->weight = (data->currentDist) / (data->distWall);//coefficiaent
			data->currentfloorX = (data->weight * data->floorXWall + (1.0 - data->weight) * data->posX);//Position sur X
			data->currentfloorY = (data->weight * data->floorYWall + (1.0 - data->weight) * data->posY);//Position sur Y
			data->floortexX = (int)(data->currentfloorX * texWidth) % texWidth;//Position Texel sur X
			data->floortexY = (int)(data->currentfloorY * texHeight) % texHeight;//Position Texel sur Y
			int	color = data->text6.data[texWidth * data->floortexY + data->floortexX];
			// if (data->side == 1)
			// {
			// 	color = (color >> 1) & 8355711;
			// }
			//printf("%f\n", data->floortexX);
			//data->img.data[y * data->win_width + data->x] = color;
			data->img.data[data->win_width * (data->win_height - y - 1) + data->x] = color;
			data->buffer[data->win_height - y - 1][data->x] = color;
			y++;
		}
		//ft_draw_sprites(data, texHeight3, texWidth3);
		data->x++;
	}

	if (data->hitSprite == 1)
	{
		int		i = 0;
		while (i < data->numSprites)
		{
			data->hitSprite = 0;
			//printf("posY %f\n",data->posY);
			//printf("spritY %f\n",data->spritY);
			double	spriteX = data->bufferSprites[i][0] + 0.5 - data->posX; //data->spritX + 0.5 - data->posX;
			double	spriteY = data->bufferSprites[i][1] + 0.5 - data->posY;//data->spritY + 0.5 - data->posY;

			double	invDet = 1.0 / (data->PlanX * data->dirY - data->dirX * data->PlanY);

			double	tranformX = invDet * (data->dirY * spriteX - data->dirX * spriteY);
			double	tranformY = invDet * (-data->PlanY * spriteX + data->PlanX * spriteY);

			int		spriteScreenX = (int)((data->win_width / 2) * (1 + tranformX / tranformY));

			int		spriteHeight = abs((int)(data->win_height / tranformY));

			int		drawStartY = -spriteHeight / 2 + data->win_height / 2;

			if (drawStartY < 0)
				drawStartY = 0;

			int		drawEndY = spriteHeight / 2 + data->win_height / 2;

			if (drawEndY >= data->win_height)
				drawEndY = data->win_height - 1;

			int		spriteWidth = abs((int)(data->win_height / tranformY));

			int		drawStartX = -spriteWidth / 2 + spriteScreenX;

			if (drawStartX < 0)
				drawStartX = 0;

			int		drawEndX = spriteWidth / 2 + spriteScreenX;

			if (drawEndX >= data->win_width)
				drawEndX = data->win_width - 1;

			int		stripe = drawStartX;
			
			while (stripe < drawEndX)
			{
				int		texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * texWidth3 / spriteWidth) / 256;
				//printf("stripe %d\n", data->Zbuffer[stripe]);
				if (tranformY > 0 && stripe > 0 && stripe < data->win_width && tranformY < data->Zbuffer[stripe] + 0.5)
				{
					y = drawStartY;
					while (y < drawEndY)
					{
						int		d = (y) * 256 - data->win_height * 128 + spriteHeight * 128;
						int		texY = ((d * texHeight3) / spriteHeight) / 256;
						int		color = data->text7.data[texWidth3 * texY + texX];
						//printf("%d\n", color);
						if ((color & 0x00FFFFFF) != 0)
						{
							//data->img.data[y * data->win_width + data->x] = color;
							//data->img.data[data->win_width * (data->win_height - y - 1) + data->x] = color;
							data->img.data[y * data->win_width + stripe] = color;
							//buffer[y][stripe] = color;
							//data->img.data[y * data->win_width + data->x] = color;
							y++;
						}
						else
						{
							data->img.data[y * data->win_width + stripe] = data->buffer[y][stripe];
							//printf("jjj\n");
							y++;
						}
							//data->img.data[data->win_width * (data->win_height - y - 1) + data->x] = buffer[y][data->x];
						//y++;
					}
				}
				stripe++;
			}
			i++;
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.ptr, 0, 0);
	// x = 0;
	// while (x < data->numSprites)
	// {
	// 	y = 0;
	// 	while (y < 3)
	// 	{
	// 		data->bufferSprites[x][y] = 0;
	// 		y++;
	// 	}
	// 	x++;
	// }
	// mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.ptr, 0, 0);
}

int		main(void)
{
	data_t	data;
	data.win_width = 920;
	data.win_height = 580;
	data.posX = 22.0;
	data.posY = 11.5;
	data.dirX = -1.0;
	data.dirY = 0.0;
	data.PlanX = 0.0;
	data.PlanY = 0.66;
	data.spritX = 19;
	data.spritY = 11.5;
	//int		bufferSprites[25][3];

	ft_memcpy(data.map, worldMap, 25*25*sizeof(int));

	if ((data.mlx_ptr = mlx_init()) == NULL)
        	return (EXIT_FAILURE);
    if ((data.mlx_win = mlx_new_window(data.mlx_ptr, data.win_width, data.win_height, "Hello world")) == NULL)
        	return (EXIT_FAILURE);
	ft_bzero(data.k, 280);
	
	int 	i = 0;
	int		x = 0;
	int		y = 0;
	while (x < mapWidth)
	{
		y = 0;
		while (y < mapHeight)
		{
			if (worldMap[x][y] == 2)
			{
				data.bufferSprites[i][0] = x;
				data.bufferSprites[i][1] = y;
				data.bufferSprites[i][2] = ((data.posX - x) * (data.posX - x)) + ((data.posY - y) * (data.posY - y));
				i++;
			}
			y++;
		}
		x++;
	}
	data.numSprites = i;
	ft_take_coord_sprites(&data);

	print_map(&data);
	//mlx_hook(data.mlx_win, 3, (1L << 1), key_release_hook, &data);
	mlx_hook(data.mlx_win, 2, (1L << 0), key_press_hook, &data);
	mlx_hook(data.mlx_win, 3, (1L << 1), key_release_hook, &data);
  	mlx_loop_hook(data.mlx_ptr, deal_key, &data);

	mlx_loop(data.mlx_ptr);
	return (EXIT_FAILURE);
}