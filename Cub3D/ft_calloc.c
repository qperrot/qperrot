/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:06:00 by qperrot-          #+#    #+#             */
/*   Updated: 2019/10/18 11:31:37 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = NULL;
	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < count * size)
	{
		((char*)ptr)[i] = 0;
		i++;
	}
	return ((void*)ptr);
}
