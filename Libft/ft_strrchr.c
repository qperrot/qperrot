/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:35:21 by qperrot-          #+#    #+#             */
/*   Updated: 2019/10/11 15:52:36 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*str;

	ptr = NULL;
	str = (char*)s;
	while (*str != '\0')
	{
		if (*str == c)
		{
			ptr = str;
		}
		++str;
	}
	if (c == 0)
		ptr = str;
	return (ptr);
}
