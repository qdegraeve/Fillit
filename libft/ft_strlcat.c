/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:17:58 by qdegraev          #+#    #+#             */
/*   Updated: 2015/12/02 17:28:51 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t left;
	size_t s_dest;
	size_t i;

	i = 0;
	s_dest = ft_strlen(dest);
	left = size - s_dest;
	if (left == 0 || size < s_dest)
		return (size + ft_strlen(src));
	while (src[i] && i < left - 1)
	{
		dest[s_dest + i] = src[i];
		i++;
	}
	dest[s_dest + i] = '\0';
	return (s_dest + ft_strlen(src));
}
