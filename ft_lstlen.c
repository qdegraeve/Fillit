/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afillion <afillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:50:50 by afillion          #+#    #+#             */
/*   Updated: 2015/12/10 21:42:33 by afillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen(t_list **alst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *alst;
	while (tmp)
	{
		ft_putstr(tmp->content); //TEST
		tmp = tmp->next;
		ft_putnbr(i);//TEST
		i++;
	}
	return (i);
}
