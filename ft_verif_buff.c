/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_buff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 03:54:48 by acalleja          #+#    #+#             */
/*   Updated: 2017/11/28 08:40:16 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_verif_buf(char *buf, int ret, int u, t_info_tetri *i_tetri)
{
	int i;
	int count;

	i = 0;
	if ((buf[i] != '.' && buf[i] != '#') || (ret < 20))
		return (0);
	while (i < ret)
	{
		count = 0;
		while (buf[i] != '\n')
		{
			if ((buf[i] != '.' && buf[i] != '#') || count++ >= 4)
				return (0);
			i++;
		}
		i++;
	}
	if (!ft_verif_tetri(i_tetri->bin, i_tetri->list, u))
		return (0);
	return (1);
}
