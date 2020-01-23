/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 08:59:56 by qperrot-          #+#    #+#             */
/*   Updated: 2019/10/18 09:53:17 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;
	size_t		len_s;
	size_t		start_s;

	str = NULL;
	i = 0;
	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	start_s = (size_t)start;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start_s > len_s)
		str[0] = '\0';
	while (len && start_s < len_s)
	{
		str[i] = s[start_s];
		i++;
		start_s++;
		len--;
	}
	str[i] = '\0';
	return (str);
}
