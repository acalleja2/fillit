# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acalleja <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/25 04:31:32 by acalleja          #+#    #+#              #
#    Updated: 2017/11/28 08:48:20 by elbenkri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit

SRC		=	ft_back.c\
			ft_get_line.c\
			ft_init_map.c\
			main.c\
			ft_verif_buff.c\
			ft_verif_tetri.c\
			ft_print_tetri.c\
			ft_tab_verif.c\
			ft_init_pattern.c\
			ft_model_verif.c\
			ft_init_carre.c\

OBJ		=	ft_back.o\
			ft_get_line.o\
			ft_init_map.o\
			main.o\
			ft_verif_buff.o\
			ft_verif_tetri.o\
			ft_print_tetri.o\
			ft_tab_verif.o\
			ft_init_pattern.o\
			ft_model_verif.o\
			ft_init_carre.o\

INCLUDES	=	fillit.h

all	: $(NAME)

$(NAME)	: $(SRC)
	gcc -Wall -Werror -Wextra -c $(SRC) -I $(INCLUDES)
	gcc -o $(NAME) $(OBJ)

clean	:
	rm -rf $(OBJ)

fclean	: clean
	rm -rf $(NAME)

re		: fclean all

.PHONY	: re fclean clean all
