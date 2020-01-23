/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:42:38 by qperrot-          #+#    #+#             */
/*   Updated: 2019/10/28 11:13:06 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	if (s[0] == '\0')
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != c)
	{
		if (*s == '\0')
			return (NULL);
		++s;
	}
	return (s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*n_str;
	size_t	i;
	size_t	lens1;
	size_t	lens2;
	size_t	j;

	n_str = NULL;
	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!(n_str = (char*)malloc(sizeof(char) * (lens1 + lens2 + 1))))
		return (NULL);
	while (j < lens1)
		n_str[i++] = s1[j++];
	j = 0;
	while (j < lens2)
		n_str[i++] = s2[j++];
	n_str[i] = '\0';
	return (n_str);
}

char	*ft_strdup(char *s1)
{
	char	*ptr;
	int		i;

	ptr = NULL;
	i = 0;
	if (!s1)
	{
		if (!(ptr = (char*)malloc(sizeof(char) * 1)))
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	while (s1[i] != '\0')
		i++;
	if (!(ptr = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char *str, size_t start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	len_s;

	new_str = NULL;
	i = 0;
	if (str == NULL)
		return (NULL);
	len_s = ft_strlen(str);
	if (!(new_str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len && start < len_s)
	{
		new_str[i] = str[start];
		i++;
		start++;
		len--;
	}
	new_str[i] = '\0';
	return (new_str);
}
