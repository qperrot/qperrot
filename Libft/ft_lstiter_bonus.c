/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 09:39:36 by qperrot-          #+#    #+#             */
/*   Updated: 2019/10/14 12:11:44 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;
	void	*data;

	tmp = lst;
	if (!lst)
		return ;
	while (tmp->next)
	{
		data = tmp->content;
		(*f)(data);
		tmp = tmp->next;
	}
	data = tmp->content;
	(*f)(data);
	return ;
}
