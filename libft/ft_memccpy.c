/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:28:31 by qdegraev          #+#    #+#             */
/*   Updated: 2015/12/02 18:48:31 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	if (ft_memchr(src, c, n) == NULL)
		return (NULL);
	else
	{
		while (i < n && ((char*)src)[i] != (char)c)
		{
			((char*)dest)[i] = ((char*)src)[i];
			i++;
		}
		return (dest + i + 1);
	}
}
