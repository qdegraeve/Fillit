/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afillion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:09:32 by afillion          #+#    #+#             */
/*   Updated: 2015/12/16 18:34:14 by qdegraev         ###   ########.fr       */
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

t_memory	mem_init(int i, int j)
{
	t_memory	new;

	ft_putendl("check board = 2");//TEST
	new.i = i;
	new.j = j;
			ft_putnbr(new.i);
			ft_putchar('\n');
			ft_putnbr(new.j);
			ft_putchar('\n');
			return (new);
}

char	**backtrack_map(t_list *lst)
{
	char	**map;
	t_memory	mem;
	int		len;
	int		n;

	len = ft_lstlen(lst);
	n = ft_small_square(len);
	map = ft_taballoc(9);
	while (lst)
	{
		mem = ft_niketamerelapute(map, lst->tab);
		if (mem.i >= 0 && mem.j >= 0)
		{
			ft_putendl("check board = 1");//TEST
			ft_fill_board(map, lst->tab, mem.i, mem.j);
			lst = lst->next;
		}
		else 
			return (map);
	}
	return (map);
}

t_memory	ft_niketamerelapute(char **map, char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (check_board(map, tab, i, j))
			{
				ft_putendl("check board = 1");//TEST
				return (mem_init(i, j));
			}
			else
				j++;
		}
		i++;
		j = 0;
	}
	return (mem_init(-1, -1));
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
