/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:25:54 by qperrot-          #+#    #+#             */
/*   Updated: 2020/01/21 10:08:02 by qperrot-         ###   ########.fr       */
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

void	ft_check_other_line(char *line, data_t *data, pars_t *pars)
{
	int		i;

	i = -1;
	while (line[++i])
	{
		if (line[0] != '1' || line[data->num_of_el - 1] != '1')
		{
			printf("ERROR INVALID MAP\n");
			exit(EXIT_FAILURE);
		}
		if (line[i] == '1' || line[i] == '0' || line[i] == '2' || line[i] == 'N'
						|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			ft_init_dir_plan(data, line[i]);
		else
		{
			printf("ERROR INVALID MAP\n");
			exit(EXIT_FAILURE);
		}
	}
	if (i < data->num_of_el || i > data->num_of_el)
	{
		printf("ERROR INVALID MAP\n");
		exit(EXIT_FAILURE);
	}
	ft_realloc(data, line, pars);
}

void	ft_check_first_line(char *line, data_t *data, pars_t *pars)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
		{
			printf("ERROR INVALID MAP\n");
			exit(EXIT_FAILURE);
		}
		else
			i++;
	}
	data->num_of_el = i;
	ft_realloc(data, line, pars);
}

void	ft_check_last_line(char *line, data_t *data, pars_t *pars)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
		{
			printf("ERROR INVALID MAP\n");
			exit(EXIT_FAILURE);
		}
		else
			i++;
	}
	if (i < data->num_of_el || i > data->num_of_el)
	{
		printf("ERROR INVALID MAP\n");
		exit(EXIT_FAILURE);
	}
	ft_realloc(data, line, pars);
}

void	ft_check_line(char *line, data_t *data, pars_t *pars)
{
	data->num_of_line += 1;
	if (pars->first_line == 0)
		ft_check_first_line(line, data, pars);
	else if (pars->last_line == 0)
		ft_check_other_line(line, data, pars);
	else if (pars->last_line == 1)
		ft_check_last_line(line, data, pars);
	else
		return ;
}
