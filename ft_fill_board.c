/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afillion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:09:32 by afillion          #+#    #+#             */
/*   Updated: 2015/12/14 16:21:53 by afillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

void	ft_fill_board(char **map, t_list *lst, int n)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (lst->tab[i])
	{
		if (lst->tab[i][j] == map[i][j])
			j++;
		if (lst->tab[i][j] != map[i][j] && j < ft_strlen(lst->tab[i]))
		{
			map[i][j] = lst->tab[i][j];
			j++;
		}
		if (lst->tab[i][j] == '\0')
		{
			i++;
			j = 0;
		}
	}
	i = 0;
	while (i < n)
	{
		ft_putendl(map[i]);
		i++;
	}
	return ;
}
