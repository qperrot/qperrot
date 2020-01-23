/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:53:28 by qperrot-          #+#    #+#             */
/*   Updated: 2019/10/15 17:24:43 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*new;
	unsigned char	*old;

	i = 0;
	new = (unsigned char*)dst;
	old = (unsigned char*)src;
	while (i < n)
	{
		new[i] = old[i];
		i++;
	}
	return ((void*)new);
}
