/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:29:33 by qperrot-          #+#    #+#             */
/*   Updated: 2020/01/23 13:57:08 by qperrot-         ###   ########.fr       */
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

void	ft_put_new_line_tmp_map(data_t *data, int **tmp_map, char *line, int j)
{
	int		i;

	while (j < data->num_of_line)
	{
		i = 0;
		while (line[i])
		{
			if (ft_isalpha(line[i]))
				line[i] = '3';
			tmp_map[j][i] = line[i] - 48;
			i++;
		}
		j++;
	}
}

void	ft_put_in_tmp_map(data_t *data, int **tmp_map, char *line)
{
	int		i;
	int		j;

	j = 0;
	while (j < data->num_of_line - 1)
	{
		i = 0;
		while (i < data->num_of_el)
		{
			tmp_map[j][i] = data->map_n[j][i];
			i++;
		}
		free(data->map_n[j]);
		j++;
	}
	ft_put_new_line_tmp_map(data, tmp_map, line, j);
	free(data->map_n);
}

void	ft_fill_tmp_map(data_t *data, int **tmp_map, char *line)
{
	int		j;
	int		i;

	j = 0;
	while (j < data->num_of_line)
	{
		i = 0;
		while (line[i])
		{
			tmp_map[j][i] = line[i] - 48;
			i++;
		}
		j++;
	}
}

void	ft_fill_map_n(data_t *data, int **tmp_map)
{
	int		i;
	int		j;

	j = 0;
	while (j < data->num_of_line)
	{
		i = 0;
		while (i < data->num_of_el)
		{
			data->map_n[j][i] = tmp_map[j][i];
			i++;
		}
		free(tmp_map[j]);
		j++;
	}
}
