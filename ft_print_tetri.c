/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 06:44:50 by acalleja          #+#    #+#             */
/*   Updated: 2017/11/28 08:36:06 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static char		**ft_alloc(char **str, int a)
{
	int k;

	k = 0;
	str = (char **)malloc(sizeof(char *) * a + 1);
	while (k < a)
	{
		str[k] = (char *)malloc(sizeof(char) * a + 1);
		str[k][a + 1] = '\0';
		k++;
	}
	str[k] = 0;
	return (str);
}

static void		print_soluc(char **str, int a)
{
	int i;
	int j;

	i = 0;
	while (i < a)
	{
		j = 0;
		while (j < a)
		{
			write(1, &str[i][j], 1);
			j++;
		}
		if (i < a - 1)
			write(1, "\n", 1);
		i++;
	}
}

static char		**ft_init(char **str, int a)
{
	int i;
	int j;

	i = 0;
	while (i < a)
	{
		j = 0;
		while (j < a)
		{
			str[i][j] = '.';
			j++;
		}
		str[i][j] = '\0';
		i++;
	}
	return (str);
}

static char		**ft_norm(t_variable *variable, unsigned int *tetri,
		int a, char **str)
{
	while (++variable->k < variable->len)
	{
		if (a > 0)
		{
			variable->j = variable->res[variable->k] % a;
			variable->i = variable->res[variable->k] / a;
		}
		variable->x = variable->i - 1;
		while (++variable->x < variable->i + 4)
		{
			variable->y = variable->j - 1;
			while (++variable->y < variable->j + 4)
			{
				if ((ft_get_line(tetri[variable->k], variable->x - variable->i)
							& (1 << (30 - (variable->y - variable->j)))) ==
						(1 << (30 - (variable->y - variable->j))))
					str[variable->x][variable->y] = variable->b;
			}
		}
		variable->b++;
	}
	return (str);
}

void			ft_print_tetri(unsigned int *tetri, t_variable *variable)
{
	char **str;

	str = NULL;
	str = ft_alloc(str, variable->dim[0]);
	ft_init(str, variable->dim[0]);
	variable->k = -1;
	variable->b = 'A';
	ft_norm(variable, tetri, variable->dim[0], str);
	print_soluc(str, variable->dim[0]);
	write(1, "\n", 1);
}
