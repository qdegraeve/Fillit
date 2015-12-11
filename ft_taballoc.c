/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_taballoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afillion <afillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:09:07 by afillion          #+#    #+#             */
/*   Updated: 2015/12/10 21:43:22 by afillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	fill_board(char **map, char **piece, int n)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < n)
	{
		j = 0;
		while (j < ft_strlen(piece[i]))
		{
			ft_putnbr(ft_strlen(piece[i]));
			ft_putchar('\n');
			if (piece[i][j] != map[i][j])
			{
				ft_putstr("if piece[i][j] = map[i][j]\n");
				ft_putchar(piece[i][j]);
				ft_putchar('\n');
				map[i][j] = piece[i][j];
				j++;
			}
			else
			{
				ft_putstr("else\n");
				j++;
			}
		}
		i++;
	}
	i = 0;
	while (i < n)
	{
		ft_putendl(map[i]);
		i++;
	}
	return ;
}

char	**ft_taballoc(int n)
{
	ft_putstr("Verif 1\n"); //TEST
	char	**new;
	int		i;

	i = 0;
	if (!(new = (char**)malloc(n * sizeof(char*))))
		return (NULL);
	while (i < n)
	{
		new[i] = (char*)malloc(n * sizeof(char));
		ft_memset(new[i], '.',n);
		ft_putendl(new[i]); //TEST
		i++;
	}
	ft_putstr("Verif 2\n");
	return (new);
}

/*int		main(int ac, char **av)
{
	char	carre[2][4] = {"##\n","##\n"};
	char	z[2][5] = {"##.\n",".##\n"};
	char	**tab;
	char	**piece;

	piece = (char**)malloc(2 * sizeof(char*));
	piece[1] = (char*)malloc(5 * sizeof(char));
	piece[2] = (char*)malloc(5 * sizeof(char));
	piece[0] = "##.\0";
	piece[1] = ".##\0";
	ft_putstr(piece[1]);
	ft_putstr(piece[2]);
	ft_putstr(carre[0]);
	ft_putstr(carre[1]);
	ft_putstr(z[0]);
	ft_putstr(z[1]);
	tab = ft_taballoc(5);
	fill_board(tab, piece, 5);
	return(0);
}*/
