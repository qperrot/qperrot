/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 09:42:07 by qperrot-          #+#    #+#             */
/*   Updated: 2019/10/16 08:51:54 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_new(void *content)
{
	t_list	*new_el;

	new_el = NULL;
	new_el = malloc(sizeof(t_list));
	if (new_el == NULL)
		return (NULL);
	new_el->content = content;
	new_el->next = NULL;
	return (new_el);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *))
{
	t_list	*list;
	t_list	*new_el;
	void	*data;

	list = NULL;
	new_el = NULL;
	if (!lst)
		return (NULL);
	data = (*f)(lst->content);
	new_el = ft_lst_new(data);
	if (new_el == NULL)
		return (NULL);
	list = new_el;
	lst = lst->next;
	while (lst)
	{
		new_el->next = ft_lst_new(f(lst->content));
		if (new_el->next == NULL)
			return (NULL);
		new_el = new_el->next;
		lst = lst->next;
	}
	return (list);
}
