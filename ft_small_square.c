/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afillion <afillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:57:24 by afillion          #+#    #+#             */
/*   Updated: 2015/12/10 21:43:32 by afillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		ft_small_square(int i)
{
	int	n;

	n = 2;
	while (i * 4 > n * n)
		n++;
	ft_putnbr(n); //TEST
	return (n);
}