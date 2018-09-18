/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 07:58:46 by acalleja          #+#    #+#             */
/*   Updated: 2017/11/28 08:39:26 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned int		ft_get_line(unsigned int tetri, int y)
{
	unsigned int tmp;
	unsigned int bit;
	unsigned int tab[4];

	tmp = tetri;
	tab[0] = tetri >> 12;
	bit = tab[0] << 12;
	tmp -= bit;
	tab[1] = tmp >> 8;
	bit = tab[1] << 8;
	tmp -= bit;
	tab[2] = tmp >> 4;
	bit = tab[2] << 4;
	tmp -= bit;
	tab[3] = tmp;
	if (y == 0)
		return (tab[0] << 27);
	if (y == 1)
		return (tab[1] << 27);
	if (y == 2)
		return (tab[2] << 27);
	else
		return (tab[3] << 27);
}
