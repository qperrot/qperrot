/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 08:35:14 by qperrot-          #+#    #+#             */
/*   Updated: 2020/01/23 14:00:14 by qperrot-         ###   ########.fr       */
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

// void	ft_get_data_img(data_t *data)
// {
// 	data->img.data = (int *)mlx_get_data_addr(data->img.ptr, &data->img.bpp,
// 					&data->img.size_l, &data->img.endian);
// 	data->text[NORTH].data = (int *)mlx_get_data_addr(data->text[NORTH].ptr,
// 					&data->text[NORTH].bpp, &data->text[NORTH].size_l, &data->text[NORTH].endian);
// 	data->text2.data = (int *)mlx_get_data_addr(data->text2.ptr,
// 					&data->text2.bpp, &data->text2.size_l, &data->text2.endian);
// 	data->text3.data = (int *)mlx_get_data_addr(data->text3.ptr,
// 					&data->text3.bpp, &data->text3.size_l, &data->text3.endian);
// 	data->text4.data = (int *)mlx_get_data_addr(data->text4.ptr,
// 					&data->text4.bpp, &data->text4.size_l, &data->text4.endian);
// 	data->text5.data = (int *)mlx_get_data_addr(data->text5.ptr,
// 					&data->text5.bpp, &data->text5.size_l, &data->text5.endian);
// 	data->text6.data = (int *)mlx_get_data_addr(data->text6.ptr,
// 					&data->text6.bpp, &data->text6.size_l, &data->text6.endian);
// 	data->text7.data = (int *)mlx_get_data_addr(data->text7.ptr,
// 					&data->text7.bpp, &data->text7.size_l, &data->text7.endian);
// }

void	ft_init_img(data_t *data)
{
	int		i;

	i = 0;
	data->x = 0;
	data->img.ptr = mlx_new_image(data->mlx_ptr, data->win_width,
					data->win_height);
	data->img.data = (int *)mlx_get_data_addr(data->img.ptr, &data->img.bpp,
					&data->img.size_l, &data->img.endian);
	// data->text[NORTH].ptr = mlx_xpm_file_to_image(data->mlx_ptr, data->text_north,
	// 				&data->texWidth, &data->texHeight);
	// data->text2.ptr = mlx_xpm_file_to_image(data->mlx_ptr, data->text_north,
	// 				&data->texWidth, &data->texHeight);
	// data->text3.ptr = mlx_xpm_file_to_image(data->mlx_ptr, data->text_north,
	// 				&data->texWidth, &data->texHeight);
	// data->text4.ptr = mlx_xpm_file_to_image(data->mlx_ptr, data->text_north,
	// 				&data->texWidth, &data->texHeight);
	// data->text5.ptr = mlx_xpm_file_to_image(data->mlx_ptr, data->text_north,
	// 				&data->texWidth2, &data->texHeight2);
	// data->text6.ptr = mlx_xpm_file_to_image(data->mlx_ptr, data->text_north,
	// 				&data->texWidth, &data->texHeight);
	// data->text7.ptr = mlx_xpm_file_to_image(data->mlx_ptr, data->text_sprite,
	// 				&data->texWidth3, &data->texHeight3);
	while (i < 5)
	{
		data->text[i].ptr = mlx_xpm_file_to_image(data->mlx_ptr, data->text[i].text,
	 				&data->text[i].width, &data->text[i].height);
		data->text[i].data = (int *)mlx_get_data_addr(data->text[i].ptr,
					&data->text[i].bpp, &data->text[i].size_l, &data->text[i].endian);
		i++;
	}
}
