/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afillion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:09:32 by afillion          #+#    #+#             */
/*   Updated: 2015/12/16 14:36:36 by afillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_fill_board(char **map, char **tab, int x, int y)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			if (ft_isalpha(tab[i][j]))
				map[x + i][y + j] = tab[i][j];
			j++;
		}
		i++;
		j = 0;
	}
	return ;
}

void	ft_niketamerelapute(char **map, t_list *lst)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && lst)
		{
			if (check_board(map, lst->tab, i, j))
			{
				ft_putendl("check board = 1");//TEST
				ft_fill_board(map, lst->tab, i, j);
				lst = lst->next;
				j = 0;
			}
			else
				j++;
		}
		i++;
	}

}

int		check_board(char **map, char **tab, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = 0;
		if (!(map[x + i]) || ft_strlen(map[x + i] + y) < ft_strlen(tab[i]))
			return (0);
		while (tab[i][j])
		{
			if (map[x + i][y + j] == '.' && ft_isalpha(tab[i][j]))
				j++;
			else if (tab[i][j] == '.')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}
