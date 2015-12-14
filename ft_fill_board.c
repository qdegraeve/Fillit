/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afillion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:09:32 by afillion          #+#    #+#             */
/*   Updated: 2015/12/14 19:34:52 by afillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

void	ft_fill_board(char **map, char **tab, int x, int y)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	ft_putendl("fill board");//TEST
	while (tab[i])
	{
		if (tab[i][j] == map[x + i][y + j])
			j++;
		if (tab[i][j] != map[x + i][y + j] && j < ft_strlen(tab[i]))
		{
			map[x + i][y + j] = tab[i][j];
			j++;
		}
		if (tab[i][j] == '\0')
		{
			i++;
			j = 0;
		}
	}
	ft_putendl("fill board fin");//TEST
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
			if (check_board(map, lst->tab, i, j) == 1)
			{
				ft_putendl("check board = 1");//TEST
				ft_fill_board(map, lst->tab, i, j);
				lst = lst->next;
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
	ft_putendl("check board entree");//TEST
	while (tab[i] && map[x + i])
	{
		j = 0;
		while (tab[i][j] && map[x + i][y + j])
		{
			ft_putnbr(j);
			ft_putendl(tab[i]);
			ft_putendl(map[x + i]);
			ft_putchar(map[x + i][y + j]);
			ft_putchar('\n');
			ft_putchar(tab[i][j]);
			ft_putchar('\n');
			if (map[x + i][y + j] == '.' && (tab[i][j] == '#' || tab[i][j] == '.'))
			{
				ft_putendl("premier if");
				j++;
			}
			/*if (map[x + i][y + j] == '#' && tab[i][j] == '.')
			{
				ft_putendl("deuxieme if");
				j++;
			}*/
			else
				return (0);
		}
		i++;
	}
	ft_putendl("check board fin");//TEST
	return (1);
}
