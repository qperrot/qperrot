/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:51:13 by qperrot-          #+#    #+#             */
/*   Updated: 2019/10/15 17:25:51 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*src_ptr;
	unsigned char	*dst_ptr;
	size_t			i;

	i = 0;
	dst_ptr = dst;
	src_ptr = (unsigned char*)src;
	if (!n)
		return (NULL);
	while (i < n && src_ptr[i] != (unsigned char)c)
	{
		dst_ptr[i] = src_ptr[i];
		i++;
	}
	if (src_ptr[i] == (unsigned char)c)
	{
		dst_ptr[i] = src_ptr[i];
		i++;
	}
	if (i == n && src_ptr[i - 1] != (unsigned char)c)
		return (NULL);
	return ((void*)(dst_ptr + i));
}
