/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 11:02:01 by qdegraev          #+#    #+#             */
/*   Updated: 2015/12/09 17:48:57 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list **begin_list, void const *content, size_t content_size, char letter)
{
	t_list	*new;
	t_list	*tmp;

	if (!(new = ft_lstnew(content, content_size, letter)))
		return ;
	if (!(*begin_list))
		*begin_list = new;
	else
	{
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
