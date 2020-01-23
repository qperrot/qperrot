/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:45:03 by qperrot-          #+#    #+#             */
/*   Updated: 2019/10/28 10:16:56 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define MAX_FD 1025

size_t	ft_strlen(char *s);
size_t	ft_check_end(char **str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
char	*ft_substr(char *str, size_t start, size_t len);
int		ft_end_of_fill(char **line, char **str);
int		ft_put_char_in_line(char **line, char **str);
int		get_next_line(int fd, char **line);
char	**ft_split(char *str, char *charset);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
int     ft_isalpha(int c);
int	    ft_isdigit(int c);
//void	*ft_memmove(void *dst, const void *src, size_t len);
//char    **ft_split(char const *s, char c);

#endif
