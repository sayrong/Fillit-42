# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/04 16:00:48 by masprigg          #+#    #+#              #
#    Updated: 2019/01/20 19:24:32 by masprigg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = check.c make_change.c map.c tetroblock.c valid.c free.c

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/ && make -C libft/ clean
	clang -c -Wall -Werror -Wextra -I libft $(SRC)
	clang -o $(NAME) *.o main.c -I libft -L libft/ -lft
clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
