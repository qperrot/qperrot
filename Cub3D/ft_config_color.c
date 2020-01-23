/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:18:35 by qperrot-          #+#    #+#             */
/*   Updated: 2020/01/23 13:56:19 by qperrot-         ###   ########.fr       */
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

void	ft_check_all_color(char **tmp)
{
	int		i;
	int		j;

	i = 1;
	while (i < 4)
	{
		j = 0;
		while (tmp[i][j])
		{
			if (!(ft_isdigit(tmp[i][j])))
			{
				printf("INVALID RGB\n");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	ft_check_color_arg(char **tmp)
{
	if (tmp[4])
	{
		printf("INVALID RGB\n");
		exit(EXIT_FAILURE);
	}
	if (tmp[1] && tmp[2] && tmp[3])
		ft_check_all_color(tmp);
	else
	{
		printf("ERROR MISSING RGB\n");
		exit(EXIT_FAILURE);
	}
}

int		ft_get_color(char *line)
{
	char	**tmp;
	char	**ptr_tmp;
	int		color;

	tmp = ft_split(line, " ,");
	ptr_tmp = tmp;
	ft_check_color_arg(tmp);
	color = ft_atoi(tmp[1]);
	color = (color << 8 | ft_atoi(tmp[2]));
	color = (color << 8 | ft_atoi(tmp[3]));
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(ptr_tmp);
	return (color);
}

void	ft_init_color_ceil(char *line, data_t *data, pars_t *pars)
{
	if (*line == 'C' && *(line + 1) == ' ')
	{
		if (pars->n_C == 0)
		{
			data->color_ceil = ft_get_color(line);
			pars->n_C = 1;
		}
		else
		{
			printf("ERROR COLOR CEIL ALREADY GIVE\n");
			exit(EXIT_FAILURE);
		}
	}
}

void	ft_init_color_floor(char *line, data_t *data, pars_t *pars)
{
	if (*line == 'F' && *(line + 1) == ' ')
	{
		if (pars->n_F == 0)
		{
			data->color_floor = ft_get_color(line);
			pars->n_F = 1;
		}
		else
		{
			printf("ERROR COLOR FLOOR ALREADY GIVE\n");
			exit(EXIT_FAILURE);
		}
	}
	ft_init_color_ceil(line, data, pars);
}
