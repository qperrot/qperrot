/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_check_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:50:45 by qperrot-          #+#    #+#             */
/*   Updated: 2020/01/23 14:54:53 by qperrot-         ###   ########.fr       */
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

void	ft_ckeck_textsp_path(char **tmp, data_t *data, int fd)
{
	if (tmp[0][0] == 'S')
	{
		data->text[SPRITE].text = ft_strdup(tmp[1]);
		if ((fd = open(data->text[SPRITE].text, O_RDONLY)) == -1)
		{
			printf("ERROR SPRITES TEXTURE PATH INVALID\n");
			exit(EXIT_FAILURE);
		}
	}
}

void	ft_ckeck_textwe_path(char **tmp, data_t *data, int fd)
{
	if (tmp[0][0] == 'W' && tmp[0][1] == 'E')
	{
		data->text[WEST].text = ft_strdup(tmp[1]);
		if ((fd = open(data->text[WEST].text, O_RDONLY)) == -1)
		{
			printf("ERROR WEST TEXTURE PATH INVALID\n");
			exit(EXIT_FAILURE);
		}
	}
	else if (tmp[0][0] == 'E' && tmp[0][1] == 'A')
	{
		data->text[EAST].text = ft_strdup(tmp[1]);
		if ((fd = open(data->text[EAST].text, O_RDONLY)) == -1)
		{
			printf("ERROR EAST TEXTURE PATH INVALID\n");
			exit(EXIT_FAILURE);
		}
	}
}

void	ft_ckeck_textns_path(char **tmp, data_t *data, int fd)
{
	if (tmp[0][0] == 'N' && tmp[0][1] == 'O')
	{
		data->text[NORTH].text = ft_strdup(tmp[1]);
		if ((fd = open(data->text[NORTH].text, O_RDONLY)) == -1)
		{
			while (*tmp)
			{
				free(*tmp);
				tmp++;
			}
			free(*tmp);
			printf("ERROR NORTH TEXTURE PATH INVALID %d\n", fd);
			exit(EXIT_FAILURE);
		}
	}
	else if (tmp[0][0] == 'S' && tmp[0][1] == 'O')
	{
		data->text[SOUTH].text = ft_strdup(tmp[1]);
		if ((fd = open(data->text[SOUTH].text, O_RDONLY)) == -1)
		{
			printf("ERROR SOUTH TEXTURE PATH INVALID\n");
			exit(EXIT_FAILURE);
		}
	}
}

void	ft_get_text_path(char *line, data_t *data)
{
	char	**tmp;
	char	**ptr_tmp;
	int		fd;

	tmp = ft_split(line, " ");
	ptr_tmp = tmp;
	fd = 0;
	if (tmp[0][1])
	{
		ft_ckeck_textns_path(tmp, data, fd);
		ft_ckeck_textwe_path(tmp, data, fd);
	}
	else
		ft_ckeck_textsp_path(tmp, data, fd);
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(ptr_tmp);
}
