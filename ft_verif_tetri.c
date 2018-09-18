/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 21:05:58 by acalleja          #+#    #+#             */
/*   Updated: 2017/11/28 08:40:25 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned int		ft_verif_tetri(int n, unsigned int *list, int k)
{
	int *tab_verif;
	int *tab;
	int i;

	i = 0;
	tab = (int *)malloc(sizeof(int) * 19);
	tab = ft_model_verif(tab);
	tab_verif = (int *)malloc(sizeof(int) * 19);
	tab_verif = ft_tab_verif(tab_verif);
	while (i < 19)
	{
		if (tab_verif[i] == n)
		{
			list[k] = tab[i];
			return (1);
		}
		i++;
	}
	return (0);
}
