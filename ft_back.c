/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_back.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 23:47:38 by acalleja          #+#    #+#             */
/*   Updated: 2017/11/28 08:37:36 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_addmap(int res, int k, unsigned int *tetri,
		t_variable *variable)
{
	variable->map[res / variable->dim[0]] += (ft_get_line(tetri[k], 0) >>
	res % variable->dim[0]);
	variable->map[res / variable->dim[0] + 1] += (ft_get_line(tetri[k], 1) >>
	res % variable->dim[0]);
	variable->map[res / variable->dim[0] + 2] += (ft_get_line(tetri[k], 2) >>
	res % variable->dim[0]);
	variable->map[res / variable->dim[0] + 3] += (ft_get_line(tetri[k], 3) >>
	res % variable->dim[0]);
	variable->res[k] = res / variable->dim[0] * variable->dim[0] +
	res % variable->dim[0];
}

static void		ft_lessmap(int k, unsigned int *tetri, t_variable *variable)
{
	if (k == 0)
	{
		variable->map = ft_init_map(variable->dim[0] + 1, variable->map);
		ft_back(tetri, variable, k, variable->dim[0] + 1);
	}
	else
	{
		variable->map[variable->res[k - 1] / variable->dim[0]] -=
		(ft_get_line(tetri[k - 1], 0) >>
		(variable->res[k - 1] % variable->dim[0]));
		variable->map[variable->res[k - 1] / variable->dim[0] + 1] -=
		(ft_get_line(tetri[k - 1], 1) >>
		(variable->res[k - 1] % variable->dim[0]));
		variable->map[variable->res[k - 1] / variable->dim[0] + 2] -=
		(ft_get_line(tetri[k - 1], 2) >>
		(variable->res[k - 1] % variable->dim[0]));
		variable->map[variable->res[k - 1] / variable->dim[0] + 3] -=
		(ft_get_line(tetri[k - 1], 3) >>
		(variable->res[k - 1] % variable->dim[0]));
	}
}

static int		ft_cond(t_variable *variable, int a)
{
	variable->dim[0] = a;
	return (1);
}

static int		is_ok(unsigned int *tetri, int res, int k, t_variable *variable)
{
	int m;

	m = 0;
	while (m < 4)
	{
		if (((ft_get_line(tetri[k], m) >> res % variable->dim[0]) |
		variable->map[res / variable->dim[0] + m]) !=
		(((unsigned long)((ft_get_line(tetri[k], m) >>
		res % variable->dim[0]) + variable->map[res / variable->dim[0] + m]))))
			m = 5;
		else
			++m;
		if (m == 4)
		{
			return (1);
		}
	}
	return (0);
}

int				ft_back(unsigned int *tetri, t_variable *variable, int k, int a)
{
	int i;
	int j;

	if (k == variable->len)
		return (ft_cond(variable, a));
	variable->dim[0] = a;
	i = -1;
	while (++i < a)
	{
		j = -1;
		while (++j < a)
		{
			if (is_ok(tetri, i * a + j, k, variable) == 1)
			{
				ft_addmap(i * a + j, k, tetri, variable);
				if ((ft_back(tetri, variable, k + 1, a)) == 1)
					return (ft_cond(variable, a));
			}
		}
	}
	ft_lessmap(k, tetri, variable);
	return (0);
}
