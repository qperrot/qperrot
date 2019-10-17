/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:10:40 by qperrot-          #+#    #+#             */
/*   Updated: 2019/10/16 13:17:07 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len_haystack;
	size_t	len_needle;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)&haystack[0]);
	if (ft_strlen(haystack) == 0)
		return (NULL);
	while (i < len && haystack[i] != '\0')
	{
		if (haystack[i] == needle[0] || needle[0] == '\0')
		{
			len_haystack = i;
			len_needle = 0;
			while (haystack[len_haystack] && needle[len_needle]
				&& len_haystack < len
				&& haystack[len_haystack++] == needle[len_needle])
				len_needle++;
			if (!needle[len_needle])
				return ((char*)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
