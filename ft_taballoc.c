/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_taballoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afillion <afillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:09:07 by afillion          #+#    #+#             */
/*   Updated: 2015/12/14 18:43:10 by afillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <stdlib.h>

/*void	fill_board(char **map, char **piece, int n)
{
	int		i;
	size_t		j;

	i = 0;
	j = 0;
	while (piece[i])
	{
		if (piece[i][j] == map[i][j])
			j++;
		ft_putnbr(ft_strlen(piece[i]));//TEST
		ft_putchar('\n');//TEST
		if (piece[i][j] != map[i][j] && j < ft_strlen(piece[i]))
		{
			ft_putstr("if piece[i][j] = map[i][j]\n");
			ft_putchar(piece[i][j]);//TEST
			ft_putchar('\n');//TEST
			map[i][j] = piece[i][j];
			j++;
		}
		if (piece[i][j] == '\0')
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
}*/

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
	new[i] = NULL;
	ft_putstr("Verif 2\n");
	return (new);
}
/*
int		main(int ac, char **av)
{
	char	**tab;
	char	**piece;

	piece = (char**)malloc(3 * sizeof(char*));
	piece[0] = (char*)malloc(4 * sizeof(char));
	piece[1] = (char*)malloc(4 * sizeof(char));
	piece[2] = (char*)malloc(sizeof(char));
	piece[0] = "##.\0";
	piece[1] = ".##\0";
	piece[2] = NULL;
	ft_putstr(piece[0]);
	ft_putstr(piece[1]);
	tab = ft_taballoc(5);
	fill_board(tab, piece, 5);
	return(0);
}*/
