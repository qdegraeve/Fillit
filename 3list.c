/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 12:34:11 by qdegraev          #+#    #+#             */
/*   Updated: 2015/12/11 17:09:34 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*list_new(void const *content, size_t content_size, char letter)
{
	t_list *new;

	if (!(new = (t_list*)malloc(sizeof(new))))
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
		new->letter = 0;
	}
	else
	{
		if (!(new->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
		new->letter = letter;
	}
	new->tab = NULL;
	new->next = NULL;
	return (new);
}

void	list_addback(t_list **begin_list, void const *content, size_t content_size, char letter)
{
	t_list*new;
	t_list*tmp;

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

void	insert_pieces(t_list *lst)
{
	int i;
	char **split;

	split = ft_strsplit(cut_empty_lin(lst->content), '\n');
	i = 0;
	if (!(lst->tab = (char**)malloc(sizeof(char*) * 5)))
		return ;
	while (split[i])
	{
		if (!(lst->tab[i] = (char*)malloc(ft_strlen(split[i]) + 1)))
			return ;
		ft_memcpy(lst->tab[i], split[i], ft_strlen(split[i]));
		i++;
	}
	lst->tab[i] = NULL;
}
