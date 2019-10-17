/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 09:31:20 by qperrot-          #+#    #+#             */
/*   Updated: 2019/10/17 10:06:54 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*current;

	current = *lst;
	tmp = current->next;
	if (!*lst || !lst || !del)
		return ;
	while (tmp)
	{
		del(current->content);
		free(current);
		current = tmp;
		tmp = current->next;
	}
	del(current->content);
	free(current);
	*lst = NULL;
	return ;
}
