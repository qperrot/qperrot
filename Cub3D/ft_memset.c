/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:44:26 by qperrot-          #+#    #+#             */
/*   Updated: 2020/01/23 10:04:24 by qperrot-         ###   ########.fr       */
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
#define EMPTY 0
#define WALL 1

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*tab;

	i = 0;
	tab = b;
	while (i < len)
	{
		tab[i] = (unsigned char)c;
		i++;
	}
	return ((void*)tab);
}
