/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:51:26 by qperrot-          #+#    #+#             */
/*   Updated: 2019/10/28 14:53:03 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_check_end(char **str)
{
	size_t	len_str;

	len_str = 0;
	if (!str || !str[0])
		return (0);
	if (str[0][0] == '\n' || str[0][0] == '\0')
		return (0);
	while ((*str)[len_str] != '\n' && (*str)[len_str] != '\0')
		len_str++;
	return (len_str);
}

int		ft_end_of_fill(char **line, char **str)
{
	line[0] = ft_strdup(*str);
	if (str)
		free(*str);
	*str = NULL;
	return (0);
}

int		ft_put_char_in_line(char **line, char **str)
{
	size_t	len_str;
	char	*tmp;
	size_t	len;

	len_str = ft_check_end(str);
	len = ft_strlen(*str);
	tmp = NULL;
	if (!str || !str[0])
		return (ft_end_of_fill(line, str));
	else if ((*str)[len_str] == '\n' && len != len_str)
	{
		line[0] = ft_substr(*str, 0, len_str);
		tmp = ft_strdup(&(*str)[len_str + 1]);
		free(*str);
		str[0] = tmp;
		return (1);
	}
	else if ((*str)[len_str] == '\n' && len == len_str)
	{
		line[0] = ft_substr(*str, 0, len_str);
		*str[0] = '\0';
		return (1);
	}
	return (ft_end_of_fill(line, str));
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	static char	*str;
	char		*tmp;

	if (fd < 0 || fd > MAX_FD || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	while (!ft_strchr(str, '\n') && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (str == NULL)
			str = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(str, buf);
			free(str);
			str = tmp;
		}
	}
	if (ret == -1)
		return (-1);
	return (ft_put_char_in_line(line, &str));
}
