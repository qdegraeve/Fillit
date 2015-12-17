/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_check_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 17:24:48 by qdegraev          #+#    #+#             */
/*   Updated: 2015/12/17 17:24:54 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*ft_recordfile(int fd)
{
	t_list *lst;
	char *buf;
	int ret;
	int i;

	i = 0;
	lst = NULL;
	buf = (char*)malloc(22);
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		list_addback(&lst, buf, 21, 'A' + i);
		i++;
	}
	if (buf[20])
		ft_errorbox();
	free(buf);
	close(fd);
	add_pieces_in_list(lst);
	return (lst);
}

void	add_pieces_in_list(t_list *lst)
{
	t_list *tmp;

	if (check_file(lst) == 1)
	{
		tmp = lst;
		while (tmp)
		{
			insert_pieces(tmp);
			tmp = tmp->next;
		}
	}
	else
		return ;
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
		return (1);
	return (ft_errorbox());
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
		return (1);
	else
		return (ft_errorbox());
}

int		check_file(t_list *lst)
{
	t_list *tmp;
	int i;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		if (check_box(tmp->content) == 1 && check_piece(tmp->content) == 1)
		{
			i++;
			tmp = tmp->next;
		}
		else
			return (ft_errorbox());
	}
	if (i > 26)
		return (ft_errorbox());
	return (1);
}
