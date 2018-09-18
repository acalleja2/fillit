/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:10:01 by acalleja          #+#    #+#             */
/*   Updated: 2017/11/28 08:40:10 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned long	*ft_trim_tetri(int *tab, int a)
{
	unsigned long i;
	unsigned long *tetris;

	i = 0;
	tetris = (unsigned long *)malloc(sizeof(unsigned long) *
			(sizeof(tab) / sizeof(int)));
	while (i < (sizeof(tab) / sizeof(int)))
	{
		tetris[i] = ft_convert((unsigned long)tab[i], a) << (63 - 4 * a);
		i++;
	}
	return (tetris);
}
