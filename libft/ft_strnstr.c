/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 08:53:11 by qdegraev          #+#    #+#             */
/*   Updated: 2015/12/04 10:15:28 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!s2[i])
		return ((char*)s1);
	while (s1[i + j] != '\0')
	{
		while (s2[j] == s1[i + j] && s2[j] && i + j < n)
			j++;
		if (s2[j] == '\0')
			return ((char*)s1 + i);
		else
			j = 0;
		i++;
	}
	return (NULL);
}
