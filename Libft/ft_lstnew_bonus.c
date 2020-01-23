/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 08:51:02 by qperrot-          #+#    #+#             */
/*   Updated: 2019/10/15 15:51:58 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
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
