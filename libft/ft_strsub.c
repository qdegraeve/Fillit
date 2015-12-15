/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:55:10 by qdegraev          #+#    #+#             */
/*   Updated: 2015/12/15 19:17:42 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (len + start > size)
		return (NULL);
	if (!(new = ft_strnew(len)))
		return (NULL);
	ft_strcpy(new, s + start);
	new[len] = '\0';
	return (new);
}
