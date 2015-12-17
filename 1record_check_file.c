/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 17:45:19 by qdegraev          #+#    #+#             */
/*   Updated: 2015/12/17 16:05:36 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*ft_recordfile(int fd)
{
	t_list *lst;
	t_list *tmp;
	char *buf;
	int ret;
	int i;

	buf = (char*)malloc(22);
	i = 0;
	lst = NULL;
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		list_addback(&lst, buf, 21, 'A' + i);
		i++;
	}
	close(fd);
	free(buf);
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

	tmp = lst;
	while (tmp)
	{
		if (check_box(tmp->content) == 1 && check_piece(tmp->content) == 1)
			tmp = tmp->next;
		else
			return (ft_errorbox());
	}
	return (1);
}

