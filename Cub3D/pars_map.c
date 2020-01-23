/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 08:45:50 by qperrot-          #+#    #+#             */
/*   Updated: 2020/01/23 14:54:45 by qperrot-         ###   ########.fr       */
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

void	ft_init_struct(pars_t *pars, data_t *data)
{
	pars->n_R = 0;
	pars->n_S = 0;
	pars->n_F = 0;
	pars->n_C = 0;
	pars->n_EA = 0;
	pars->n_NO = 0;
	pars->n_SO = 0;
	pars->n_WE = 0;
	pars->first_line = 0;
	pars->last_line = 0;
	data->num_of_line = 0;
	data->num_of_el = 0;
	data->player = 0;
}

void	ft_check_arg_error(pars_t *pars, int ret)
{
	if (ret == -1)
	{
		printf("ERROR FILE DESCRIPTOR\n");
		exit(EXIT_FAILURE);
	}
	if (pars->n_R == 0 || pars->n_NO == 0 || pars->n_SO == 0
		|| pars->n_WE == 0 || pars->n_EA == 0
		|| pars->n_S == 0 || pars->n_F == 0 || pars->n_C == 0)
	{
		printf("ERROR ARGUMENTS ARE MISSING\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_pars_elem(data_t *data, pars_t *pars, char *line, char *buf)
{
	if (pars->n_R == 1 && pars->n_NO == 1 && pars->n_SO == 1
		&& pars->n_WE == 1 && pars->n_EA == 1 && pars->n_S == 1
		&& pars->n_F == 1 && pars->n_C == 1)
	{
		buf = ft_count_el(line);
		if (*buf == '1')
			ft_check_line(buf, data, pars);
		else if (*buf)
		{
			free(buf);
			printf("ERROR INVALID MAP\n");
			exit(EXIT_FAILURE);
		}
		free(buf);
	}
}

char	*ft_count_el(char *line)
{
	int		i;
	int		el;

	i = 0;
	el = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			el++;
		i++;
	}
	return (ft_creat_buf(line, el));
}

char	*ft_creat_buf(char *line, int el)
{
	int		i;
	char	*buf;

	if (!(buf = (char*)malloc(sizeof(char) * (el + 1))))
	{
		printf("ERROR MALLOC\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	el = 0;
	while (line[i])
	{
		if (line[i] != ' ')
		{
			buf[el] = line[i];
			el++;
		}
		i++;
	}
	buf[el] = '\0';
	return (buf);
}

int		ft_last_line(pars_t *pars, data_t *data, char *line, char *buf)
{
	pars->last_line = 1;
	buf = ft_count_el(line);
	if (*buf == '1')
	{
		ft_check_line(buf, data, pars);
		free(buf);
		buf = NULL;
		return (1);
	}
	else
		return (0);
}

void	ft_parsing_arg(data_t *data, pars_t *pars, int fd)
{
	char	*line;
	int		ret;
	char	*buf;

	buf = NULL;
	while ((ret = get_next_line(fd, &line)) >= 0)
	{
		ft_pars_elem(data, pars, line, buf);
		if (ret == 0 && pars->last_line == 0)
		{
			if (ft_last_line(pars, data, line, buf) == 1)
				break ;
		}
		if (*line == 'R' && *(line + 1) == ' ')
			ft_init_resolution(line, data, pars);
		ft_init_textno_path(line, data, pars);
		ft_init_color_floor(line, data, pars);
		free(line);
	}
	free(line);
	ft_check_arg_error(pars, ret);
	ft_check_xpm(data);
	ft_find_player(data);
}

// void	ft_check_arg(pars_t *pars, data_t *data)
// {
// 	int		fd;

// 	ft_init_struct(pars, data);
// 	fd = open("./test.cub", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("INVALID FILE\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	ft_parsing_arg(data, pars, fd);
// }
