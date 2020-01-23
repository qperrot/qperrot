/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:28:22 by qperrot-          #+#    #+#             */
/*   Updated: 2020/01/23 13:59:39 by qperrot-         ###   ########.fr       */
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

void	ft_get_resolution(char *line, data_t *data)
{
	char	**tmp;
	char	**ptr_tmp;

	tmp = ft_split(line, " ");
	ptr_tmp = tmp;
	data->win_width = ft_atoi(tmp[1]);
	data->win_height = ft_atoi(tmp[2]);
	if (data->win_width < 0 || data->win_height < 0)
	{
		printf("ERROR INVALIDE RESOLUTION\n");
		exit(EXIT_FAILURE);
	}
	if (data->win_width > 2560 || data->win_height > 1440)
	{
		data->win_width = 2560;
		data->win_height = 1440;
	}
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(ptr_tmp);
}

void	ft_init_resolution(char *line, data_t *data, pars_t *pars)
{
	if (pars->n_R == 0)
	{
		ft_get_resolution(line, data);
		pars->n_R = 1;
	}
	else
	{
		printf("ERROR TOO MANY RESOLUTION\n");
		exit(EXIT_FAILURE);
	}
}
