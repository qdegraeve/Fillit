/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_taballoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afillion <afillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:09:07 by afillion          #+#    #+#             */
/*   Updated: 2015/12/16 14:37:10 by afillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_taballoc(int n)
{
	char	**new;
	int		i;

	i = 0;
	if (!(new = (char**)malloc((n + 1) * sizeof(char*))))
		return (NULL);
	while (i < n)
	{
		new[i] = (char*)malloc((n + 1)* sizeof(char));
		ft_memset(new[i], '.', n);
		ft_putendl(new[i]); //TEST
		new[i][n] = '\0';
		i++;
	}
	new[i] = NULL;
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
