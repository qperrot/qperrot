/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 08:45:28 by qperrot-          #+#    #+#             */
/*   Updated: 2019/10/14 18:17:08 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_put_nb(int n, long num, long div, char *str)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	if (n < 0)
		str[i++] = '-';
	nb = num;
	if (nb >= 10)
		div /= 10;
	while (div > 0)
	{
		nb = num / div;
		nb = nb % 10;
		str[i] = nb + '0';
		div /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nb;
	long	div;
	long	num;

	div = 1;
	nb = 0;
	i = 0;
	num = (long)n;
	if (n < 0)
		num *= -1;
	nb = num;
	if (nb < 10)
		i++;
	while (nb >= 10)
	{
		nb = num / div;
		div *= 10;
		i++;
	}
	if (!(str = malloc(sizeof(char) * (i + 2))))
		return (NULL);
	return (ft_put_nb(n, num, div, str));
}
