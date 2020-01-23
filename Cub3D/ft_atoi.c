/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:53:58 by qperrot-          #+#    #+#             */
/*   Updated: 2019/10/18 12:14:14 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_len_str(int i, const char *str, int neg)
{
	long	count;

	count = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		count++;
		i++;
	}
	if (count >= 20 && neg == -1)
		return (0);
	else if (count >= 20 && neg == 1)
		return (-1);
	return (1);
}

static int	ft_check_whitespace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	long	nbr;
	int		i;
	int		neg;
	int		count;

	i = ft_check_whitespace(str);
	nbr = 0;
	neg = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	count = ft_len_str(i, str, neg);
	if (count != 1)
		return (count);
	while (str[i] >= 48 && str[i] <= 57)
	{
		nbr += str[i] - 48;
		nbr *= 10;
		i++;
	}
	nbr /= 10;
	return ((int)(nbr *= neg));
}
