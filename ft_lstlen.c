/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afillion <afillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:50:50 by afillion          #+#    #+#             */
/*   Updated: 2015/12/14 16:02:02 by afillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

int		ft_lstlen(t_list *lst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		ft_putstr(tmp->content); //TEST
		tmp = tmp->next;
		ft_putnbr(i);//TEST
		i++;
	}
	return (i);
}
