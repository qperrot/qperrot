/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 09:18:38 by qperrot-          #+#    #+#             */
/*   Updated: 2019/10/15 10:30:03 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	lens1;
	size_t	lens2;
	size_t	j;

	str = NULL;
	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (lens1 + lens2) + 1);
	if (!str)
		return (NULL);
	while (j < lens1)
		str[i++] = s1[j++];
	j = 0;
	while (j < lens2)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
