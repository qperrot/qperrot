/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:18:23 by qperrot-          #+#    #+#             */
/*   Updated: 2020/01/23 14:01:55 by qperrot-         ###   ########.fr       */
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

void	ft_malloc_map_n(data_t *data)
{
	int		i;

	if (!(data->map_n = (int**)malloc(sizeof(int*) * (data->num_of_line))))
	{
		printf("ERROR MAP MALLOC\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < data->num_of_line)
	{
		if (!(data->map_n[i] = (int*)malloc(sizeof(int) * (data->num_of_el))))
		{
			printf("ERROR MAP MALLOC\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	ft_realloc(data_t *data, char *line, pars_t *pars)
{
	int		i;
	int		**tmp_map;

	i = 0;
	if (!(tmp_map = (int**)malloc(sizeof(int*) * (data->num_of_line))))
	{
		printf("ERROR MAP MALLOC\n");
		exit(EXIT_FAILURE);
	}
	while (i < data->num_of_line)
	{
		if (!(tmp_map[i] = (int*)malloc(sizeof(int) * (data->num_of_el))))
		{
			printf("ERROR MAP MALLOC\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (pars->first_line == 0)
	{
		ft_fill_tmp_map(data, tmp_map, line);
		pars->first_line = 1;
	}
	else if (pars->first_line == 1)
		ft_put_in_tmp_map(data, tmp_map, line);
	ft_malloc_map_n(data);
	ft_fill_map_n(data, tmp_map);
	free(tmp_map);
}
