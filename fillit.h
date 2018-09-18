/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 03:58:46 by acalleja          #+#    #+#             */
/*   Updated: 2017/11/28 08:40:50 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define Y0 ((ft_get_line(i) | tab[i]) == ft_get_line(i) + tab[i])
# define Y1 (ft_get_line(i + 1) | tab[i + 1]) == ft_get_line(i + 1) + tab[i + 1]

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_info_tetri
{
	int				bin;
	unsigned int	list[26];
	int				tmp;
}				t_info_tetri;

typedef struct	s_variable
{
	unsigned int	*map;
	int				res[26];
	int				len;
	int				dim[1];
	unsigned int	tab[32];
	char			b;
	int				x;
	int				y;
	int				i;
	int				j;
	int				m;
	int				k;
	int				fd;
}				t_variable;

int				ft_init_pattern(char *s);
int				ft_verif_buf(char *s, int ret, int u, t_info_tetri *i_tetri);
char			*ft_clean_n(char *s);
unsigned int	ft_verif_tetri(int n, unsigned int *list, int i);
int				*ft_model_verif(int *tab);
int				*ft_tab_verif(int *tab);
unsigned long	*ft_trim_tetri(int *tab, int a);
unsigned int	ft_get_line(unsigned int tetri, int y);
int				ft_back(unsigned int *tetri, t_variable *variable,
		int k, int a);
void			ft_print_tetri(unsigned int *tetri, t_variable *variable);
unsigned int	*ft_init_map(int a, unsigned int *tab);
int				ft_init_carre(int n);

#endif
