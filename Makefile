# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/01 17:34:35 by hmzah             #+#    #+#              #
#    Updated: 2019/12/24 18:32:49 by hmzah            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

LIB = libft.a

SRC = src/b_tree.c \
	  src/b_tree_2.c \
	  src/b_tree_3.c \
	  src/biggest_size.c \
	  src/dir_managing.c \
	  src/flags_managing.c \
	  src/ft_ls.c \
	  src/is_you_is_or_is_you_aint_my_baby.c \
	  src/ls_utils_l.c \
	  src/ls_utils_l_2.c \
	  src/ls_utils_l_3.c \
	  src/sort_ascii.c \
	  src/sort_time.c \
	  src/useless_norm.c

all: $(NAME)

$(NAME): $(LIB)
	gcc -g -Wall -Wextra -Werror $(SRC) libft/$(LIB) -o $(NAME)

$(LIB):
	make -C libft

clean:
	make clean -C libft

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all
