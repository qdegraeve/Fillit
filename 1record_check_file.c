/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 17:45:19 by qdegraev          #+#    #+#             */
/*   Updated: 2015/12/15 12:04:12 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*ft_recordfile(int fd)
{
	t_list *lst;
	t_list *tmp;
	char buf[22];
	int ret;
	int i;

	i = 0;
	lst = NULL;
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		ft_putstr(buf);
		list_addback(&lst, buf, 21, 'A' + i);
		i++;
	}
	ft_putendl("lecture terminee");
	if (i > 26)
		return (NULL);
	if (check_file(lst) == 1)
	{
		tmp = lst;
		while (tmp)
		{
			insert_pieces(tmp);
			tmp = tmp->next;
		}
		return (lst);
	}
	else
		return (NULL);
}

int		check_piece(char *piece)
{
	int i;
	int n;
	int part;

	n = 0;
	part = 0;
	i = 0;
	while (piece[i])
	{
		if (piece[i] == '#')
		{
			if (piece[i - 1] == '#') 
				part++;
			if (piece[i + 1] == '#')
				part++;
			if (piece[i - 5] == '#')
				part++;
			if (piece[i + 5] == '#')
				part++;
			n++;
		}
		i++;
	}
	if ((part == 6 || part == 8) && n == 4)
	{
		ft_putendl("tetriminos conformes");
		return (1);
	}
	return (0);
}

int		check_box(char *s)
{
	int i;
	int n;
	int linefeed;

	n = 0;
	i = 0;
	linefeed = 1;
	while (s[i] && i <= 19)
	{
		if (n == 4 && s[i] == '\n')
		{
			linefeed++;
			n = 0;
		}
		if ((s[i] == '.' || s[i] == '#') && n < 4)
			n++;
		i++;
	}
	if (linefeed == 5 && (s[i] == '\n' || s[i] == '\0'))
	{
		ft_putendl("boite conforme");
		return (1);
	}
	else
		return (0);
}

int		check_file(t_list *lst)
{
	t_list *tmp;
	int i;

	tmp = lst;
	i = 1;
	while (tmp)
	{
			ft_putstr("boucle ");
			ft_putnbr(i);
			ft_putchar('\n');
			i++;
		if (check_box(tmp->content) == 1 && check_piece(tmp->content) == 1)
			tmp = tmp->next;
		else
		{
			ft_putendl("erreur fichier incorrect");
			return (0);
		}
	}
	return (1);
}

