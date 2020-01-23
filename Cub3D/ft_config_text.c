/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:18:42 by qperrot-          #+#    #+#             */
/*   Updated: 2020/01/20 14:53:22 by qperrot-         ###   ########.fr       */
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

void	ft_init_textsp_path(char *line, data_t *data, pars_t *pars)
{
	if (*line == 'S' && *(line + 1) == ' ')
	{
		if (pars->n_S == 0)
		{
			ft_get_text_path(line, data);
			pars->n_S = 1;
		}
		else
		{
			printf("ERROR SPRITES TEXTURE\n");
			exit(EXIT_FAILURE);
		}
	}
}

void	ft_init_textea_path(char *line, data_t *data, pars_t *pars)
{
	if (*line == 'E' && *(line + 1) == 'A')
	{
		if (pars->n_EA == 0)
		{
			ft_get_text_path(line, data);
			pars->n_EA = 1;
		}
		else
		{
			printf("ERROR EAST TEXTURE\n");
			exit(EXIT_FAILURE);
		}
	}
}

void	ft_init_textwe_path(char *line, data_t *data, pars_t *pars)
{
	if (*line == 'W' && *(line + 1) == 'E')
	{
		if (pars->n_WE == 0)
		{
			ft_get_text_path(line, data);
			pars->n_WE = 1;
		}
		else
		{
			printf("ERROR WEST TEXTURE\n");
			exit(EXIT_FAILURE);
		}
	}
}

void	ft_init_textso_path(char *line, data_t *data, pars_t *pars)
{
	if (*line == 'S' && *(line + 1) == 'O')
	{
		if (pars->n_SO == 0)
		{
			ft_get_text_path(line, data);
			pars->n_SO = 1;
		}
		else
		{
			printf("ERROR SOUTH TEXTURE\n");
			exit(EXIT_FAILURE);
		}
	}
}

void	ft_init_textno_path(char *line, data_t *data, pars_t *pars)
{
	if (*line == 'N' && *(line + 1) == 'O')
	{
		if (pars->n_NO == 0)
		{
			ft_get_text_path(line, data);
			pars->n_NO = 1;
		}
		else
		{
			printf("ERROR NORTH TEXTURE\n");
			exit(EXIT_FAILURE);
		}
	}
	ft_init_textso_path(line, data, pars);
	ft_init_textwe_path(line, data, pars);
	ft_init_textea_path(line, data, pars);
	ft_init_textsp_path(line, data, pars);
}
