#include "fillit.h"

void	erase_piece(char **map, char **tab, int x, int y)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			if (ft_isalpha(tab[i][j]))
				map[x + i][y + j] = '.';
			j++;
		}
		i++;
		j = 0;
	}
	return ;
}
