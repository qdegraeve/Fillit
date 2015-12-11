/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 17:53:28 by qdegraev          #+#    #+#             */
/*   Updated: 2015/12/11 17:03:04 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_errorbox()
{
	ft_putendl("error");
}

void ft_printlist(t_list *lst)
{
	t_list *tmp;
	int i;

	tmp = lst;
	while (tmp)
	{
		ft_putchar(tmp->letter);
		ft_putchar('\n');
//		ft_putendl(tmp->content);
		i = 0;
		while (tmp->tab[i])
		{
			ft_putendl(tmp->tab[i]);
			i++;
		}
		tmp = tmp->next;
	}
}

int main(int argc, char **argv)
{
	int fd;
	t_list *lst;

	if (argc != 2)
		return (0);
	lst = NULL;
	fd = open(argv[1], O_RDONLY);
	lst = ft_recordfile(fd);
	ft_printlist(lst);
}