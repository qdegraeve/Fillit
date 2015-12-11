/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:20:13 by qdegraev          #+#    #+#             */
/*   Updated: 2015/12/04 16:20:19 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s) - 1;
	while ((s[i] == 32 || s[i] == 44 || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	while ((s[j] == 32 || s[j] == 44 || s[j] == '\n' || s[j] == '\t') && j > i)
		j--;
	if (!s[i] || (i + j == 0))
		return (ft_strnew(1));
	new = ft_strsub(s, i, (j - i + 1));
	return (new);
}
