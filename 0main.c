/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 17:53:28 by qdegraev          #+#    #+#             */
/*   Updated: 2015/12/17 14:44:53 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_errorbox()
{
	ft_putendl("error");
}

int main(int argc, char **argv)
{
	int		fd;
	t_list *lst;
	char	**map;
	int		i;
	int		len;
	int		n;

	if (argc != 2)
		return (0);
	lst = NULL;
	fd = open(argv[1], O_RDONLY);
	lst = ft_recordfile(fd);
	len = ft_lstlen(lst);
	n = ft_small_square(len);
	map = map_expand(lst, n);
	list_erase(&lst);
	i = 0;
	while (i < n)
	{
		ft_putendl(map[i]);
		i++;
	}
}
