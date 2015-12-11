/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:07:07 by qdegraev          #+#    #+#             */
/*   Updated: 2015/12/04 16:18:04 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char *dest;

	if (!(dest = (char*)malloc(sizeof(*dest) * (ft_strlen(s) + 1))))
		return (NULL);
	return (ft_strcpy(dest, s));
}
