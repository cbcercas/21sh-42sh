# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/05 12:29:27 by gpouyat           #+#    #+#              #
#    Updated: 2017/06/18 13:48:25 by gpouyat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re norme main

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = libtree.a

C_NO = \033[0m
C_G = \033[0;32m
C_Y = \033[1;33m
C_B = \033[1;34m
C_C = \033[1;36m
C_R = \033[1;31m

SRC_PATH = ./sources
INC_PATH = ./includes
OBJ_PATH = ./obj

SRC_NAME = btree_apply_infix.c btree_destroy.c  btree_apply_prefix.c\
 						btree_apply_suffix.c btree_create_node.c btree_insert_data.c\
						  btree_level_count.c  btree_search_item.c btree_print.c

INC_NAME = ft_btree.h

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ) $(OBJLIB)
	@ranlib $(NAME)
	@printf "                             "
	@printf "\n\n $(C_B)%s$(C_NO)\n" "[--- LIBTREE COMPILATION DONE ---]"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) -o $@ $(FLAGS) -c $< -I includes
	@printf "$(C_B)compiling...>$(C_NO)$(C_Y)[ %-25s]\n$(C_NO)" $@

clean:
	@rm -rf $(OBJ) $(OBJLIB)
	@rm -rf includes/libft.h.gch
	@rm -rf includes/get_next_line.h.gch
	@printf "$(C_B)%-20s\t$(C_Y)Cleaning obj\t$(C_G)[ OK ✔ ]$(C_NO)\n" $(NAME)

fclean: clean
	@rm -rf ./obj $(NAME)
	@rm -rf maintest
	@printf "$(C_B)%-20s\t$(C_Y)Cleaning lib\t$(C_G)[ OK ✔ ]$(C_NO)\n" $(NAME)

re: fclean all

norme:
		@norminette $(SRC) $(LIB) $(INC)
		@printf "$(C_B)%-20s\t$(C_Y)Norminette\t$(C_G)[ OK ✔ ]$(C_NO)\n" $(NAME)

main: $(NAME)
	@$(CC) $(FLAGS) -o maintest main.c $(NAME) -I libft -I includes
	@printf "$(C_B)%-20s\t$(C_Y)compilation\t$(C_G)[ OK ✔ ]$(C_NO)\n" "maintest"
