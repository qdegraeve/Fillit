/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 09:22:23 by qdegraev          #+#    #+#             */
/*   Updated: 2015/12/04 15:16:34 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *dest;

	dest = (void*)malloc(sizeof(dest) * (size));
	if (!dest)
		return (NULL);
	ft_bzero(dest, size);
	return (dest);
}
