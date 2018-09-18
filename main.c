/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:21:36 by acalleja          #+#    #+#             */
/*   Updated: 2017/11/28 08:43:46 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_is_check_argc(int argc)
{
	if (argc != 2)
	{
		write(1, "usage : ./fillit PATH/FILE \n", 28);
		return (0);
	}
	return (1);
}

static int		ft_finish(t_info_tetri *i_tetri, t_variable *variable, int i)
{
	if (i_tetri->tmp != 20)
	{
		write(1, "error\n", 6);
		return (0);
	}
	variable->map = ft_init_map(ft_init_carre(i), variable->tab);
	variable->len = i;
	ft_back(i_tetri->list, variable, 0, ft_init_carre(i));
	ft_print_tetri(i_tetri->list, variable);
	close(variable->fd);
	return (1);
}

int				main(int argc, char **argv)
{
	int				i;
	int				ret;
	char			buf[21];
	t_info_tetri	i_tetri;
	t_variable		variable;

	i = 0;
	if (!ft_is_check_argc(argc))
		return (0);
	variable.fd = open(argv[1], O_RDONLY);
	while ((ret = read(variable.fd, buf, 21)))
	{
		buf[ret] = '\0';
		i_tetri.bin = ft_init_pattern(buf);
		if (!ft_verif_buf(buf, ret, i, &i_tetri))
		{
			write(1, "error\n", 6);
			return (0);
		}
		i_tetri.tmp = ret;
		i++;
	}
	if (!ft_finish(&i_tetri, &variable, i))
		return (0);
	return (0);
}
