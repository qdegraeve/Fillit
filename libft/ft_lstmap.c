/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 09:48:26 by qdegraev          #+#    #+#             */
/*   Updated: 2015/12/09 17:48:34 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;

	if (lst == NULL || f == NULL)
		return (NULL);
	new = ft_lstnew(f(lst)->content, f(lst)->content_size, f(lst)->letter);
	lst = lst->next;
	while (lst)
	{
		new->next = ft_lstnew(f(lst)->content, f(lst)->content_size, f(lst)->letter);
		lst = lst->next;
	}
	return (new);
}
