/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:35:46 by qperrot-          #+#    #+#             */
/*   Updated: 2019/10/16 08:44:01 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_put_in_str(char const *s1, char *str, size_t begin, size_t len)
{
	size_t	i;

	i = 0;
	if (len == 0)
	{
		str[i] = '\0';
		return (str);
	}
	while (begin < len && s1[begin])
	{
		str[i] = s1[begin];
		i++;
		begin++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_len_count(char const *set, char const *s1, size_t len)
{
	int		i;

	i = 0;
	while (set[i] && s1[len - 1])
	{
		if (set[i] == s1[len - 1])
		{
			len--;
			i = 0;
		}
		else
			i++;
	}
	return (len);
}

size_t	ft_begin_count(char const *set, char const *s1)
{
	int		i;
	size_t	begin;

	i = 0;
	begin = 0;
	while (set[i] && s1[begin])
	{
		if (set[i] == s1[begin])
		{
			begin++;
			i = 0;
		}
		else
			i++;
	}
	return (begin);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	size_t	len;
	size_t	begin;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	str = NULL;
	i = 0;
	begin = 0;
	if (!(str = (char*)malloc(sizeof(str) * len + 1)) || s1 == NULL)
		return (NULL);
	begin = ft_begin_count(set, s1);
	if (begin == len)
	{
		str[0] = '\0';
		return (str);
	}
	len = ft_len_count(set, s1, len);
	return (ft_put_in_str(s1, str, begin, len));
}
