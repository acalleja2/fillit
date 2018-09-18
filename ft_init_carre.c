/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_carre.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 00:38:00 by acalleja          #+#    #+#             */
/*   Updated: 2017/11/28 08:39:36 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_init_carre(int len)
{
	int surface;
	int i;

	i = 0;
	surface = len * 4;
	while (i * i < surface)
		i++;
	return (i);
}
