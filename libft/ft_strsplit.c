/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:39:32 by qdegraev          #+#    #+#             */
/*   Updated: 2015/12/10 16:37:46 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		count_words(char const *s, char c)
{
	size_t	i;
	size_t	stab;
	size_t	newword;

	newword = 1;
	i = 0;
	stab = 0;
	while (s[i])
	{
		if (s[i] == c && newword == 0)
			newword = 1;
		if (newword == 1 && s[i] != c)
		{
			newword = 0;
			stab++;
		}
		i++;
	}
	return (stab);
}

static int		count_letters(char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**new;
	int		i;
	int		sl;
	int		c_words;

	sl = 0;
	i = 0;
	if (!s)
		return (NULL);
	c_words = count_words(s, c);
	new = ft_memalloc(c_words + 1);
	while (s[sl] && i < c_words)
	{
		while (s[sl] == c)
			sl++;
		if (s[sl] != c)
		{
			new[i] = ft_strsub(s, sl, count_letters(s + sl, c));
			sl = sl + count_letters(s + sl, c) + 1;
			i++;
		}
	}
	new[i] = NULL;
	return (new);
}
