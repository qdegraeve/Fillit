/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 08:52:43 by qdegraev          #+#    #+#             */
/*   Updated: 2015/12/02 17:33:40 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!s2[i])
		return ((char*)s1);
	while (s1[i + j] != '\0')
	{
		while (s2[j] == s1[j + i] && s2[j])
			j++;
		if (s2[j] == '\0')
			return ((char*)s1 + i);
		else
			j = 0;
		i++;
	}
	return (NULL);
}
