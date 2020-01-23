/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 08:50:13 by qperrot-          #+#    #+#             */
/*   Updated: 2019/10/15 17:27:18 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*ptrsrc;
	char	*ptrdest;

	ptrsrc = (char*)src;
	ptrdest = (char*)dst;
	i = 0;
	if (dst < src)
	{
		while (i < len)
		{
			((char*)dst)[i] = ((char*)src)[i];
			i++;
		}
		return ((void*)dst);
	}
	if (dst > src)
	{
		while (len > 0)
		{
			ptrdest[len - 1] = ptrsrc[len - 1];
			len--;
		}
	}
	return ((void*)ptrdest);
}
