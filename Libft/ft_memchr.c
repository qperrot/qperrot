/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:14:43 by qperrot-          #+#    #+#             */
/*   Updated: 2019/10/14 13:52:29 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;
	unsigned char	*src;

	ptr = NULL;
	i = 0;
	src = (unsigned char*)s;
	while (i < n)
	{
		if (src[i] == (unsigned char)c)
		{
			ptr = &src[i];
			return ((void*)ptr);
		}
		i++;
	}
	return ((void*)ptr);
}
