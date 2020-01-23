/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:25:02 by qperrot-          #+#    #+#             */
/*   Updated: 2020/01/23 15:36:10 by qperrot-         ###   ########.fr       */
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

void	ft_print_error()
{
	printf("INVALID FILE\n");
	exit(EXIT_FAILURE);
}

void	ft_check_xpm(data_t *data)
{
	int		i;
	int		len;

	i = 0;
	while (i < 5)
	{
		len = ft_strlen(data->text[i].text);
		if (data->text[i].text[len - 4])
		{
			if ((data->text[i].text[len - 1] != 'm' &&
				data->text[i].text[len - 1] != 'M') ||
				(data->text[i].text[len - 2] != 'p' &&
				data->text[i].text[len - 2] != 'P') ||
				(data->text[i].text[len - 3] != 'x' &&
				data->text[i].text[len - 3] != 'X') ||
				data->text[i].text[len - 4] != '.')
				ft_print_error();
		}
		else
			ft_print_error();
		i++;
	}
}

void	ft_check_file(data_t *data, int argc, char *argv[])
{
	int		i;

	i = ft_strlen(argv[1]);
	if (argv[1][i - 4])
	{
		if (argv[1][i - 1] != 'b' || argv[1][i - 2] != 'u'
			|| argv[1][i - 3] != 'c' || argv[1][i - 4] != '.')
			ft_print_error();
	}
	else
		ft_print_error();
	if (argc == 3)
	{
		if (ft_strncmp(argv[2], "-save", 5) != 0)
		{
			printf("INVALID ARGUMENTS\n");
			exit(EXIT_FAILURE);
		}
		data->save = 1;
	}
}

void	ft_check_arg(pars_t *pars, data_t *data, int argc, char *argv[])
{
	int		fd;

	if (argc < 2 || argc > 3)
	{
		printf("INVALID ARGUMENTS\n");
		exit(EXIT_FAILURE);
	}
	ft_check_file(data, argc, argv);
	ft_init_struct(pars, data);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_print_error();
	ft_parsing_arg(data, pars, fd);
}
