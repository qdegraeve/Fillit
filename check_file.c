/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 09:42:02 by qdegraev          #+#    #+#             */
/*   Updated: 2015/12/07 16:34:47 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_errorbox()
{
	ft_putendl("error");
}

t_list	*ft_recordfile(int fd)
{
	t_list *lst;
	char buf[22];
	int ret;

	lst = NULL;
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret + 1] = '\0';
		ft_putstr(buf);
		ft_lstaddback(&lst, buf, 22);
	}
	return (lst);
}

void ft_printlist(t_list *lst)
{
	t_list *tmp;

	tmp = lst;
	while (tmp)
	{
		ft_putstr(tmp->content);
		tmp = tmp->next;
	}
}

int main(int argc, char **argv)
{
	int fd;
	t_list *lst;

	lst = NULL;
	fd = open(argv[1], O_RDONLY);
	ft_putchar('\n');
	lst = ft_recordfile(fd);
	ft_putendl("test2");
	ft_printlist(lst);
}
