/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:38:55 by qperrot-          #+#    #+#             */
/*   Updated: 2019/10/15 10:00:27 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	**ft_free_all(char **str, int i)
{
	while (i--)
		free(str[i]);
	free(str);
	return (0);
}

char	**ft_put_char(char **str, char const *s, char c, int words)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	i = 0;
	k = 0;
	while (s[j] != '\0' && i < words)
	{
		k = 0;
		while (s[j] == c && s[j])
			j++;
		while (s[j] != c && s[j])
		{
			str[i][k] = s[j];
			k++;
			j++;
		}
		str[i][k] = '\0';
		if (str[i][0] == '\0')
			i--;
		i++;
	}
	str[i] = NULL;
	return (str);
}

int		ft_len_words(char const *s, int *ptr, char c)
{
	int		len;

	len = 0;
	while (s[*ptr] != '\0' && s[*ptr] != c)
	{
		len++;
		*ptr = *ptr + 1;
	}
	return (len);
}

int		ft_words(char const *s, char c)
{
	int		i;
	int		words;

	i = 0;
	if (!s[0])
		return (0);
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
		{
			while (s[i] == c && s[i] != '\0')
				i++;
		}
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		words;
	int		len_words;
	int		i;
	int		ptr;

	i = 0;
	ptr = 0;
	str = NULL;
	if (s == NULL)
		return (str);
	words = ft_words(s, c);
	if (!(str = (char**)malloc(sizeof(char*) * (words + 1))) || s == NULL)
		return (NULL);
	while (s[ptr])
	{
		while (s[ptr] == c)
			ptr = ptr + 1;
		len_words = ft_len_words(s, &ptr, c);
		if (!(str[i] = (char*)malloc(sizeof(char) * (len_words + 1))))
			return (ft_free_all(str, i));
		i++;
	}
	return (ft_put_char(str, s, c, words));
}
