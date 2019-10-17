/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:48:55 by qperrot-          #+#    #+#             */
/*   Updated: 2019/10/17 14:30:32 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	sizedst;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (dst[i] && i < dstsize)
		i++;
	sizedst = i;
	while (src[i - sizedst] && i < dstsize - 1)
	{
		dst[i] = src[i - sizedst];
		i++;
	}
	if (sizedst < dstsize)
		dst[i] = '\0';
	return (sizedst + ft_strlen(src));
}
