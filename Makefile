# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbelkaid <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/16 04:06:28 by nbelkaid          #+#    #+#              #
#    Updated: 2016/03/16 04:06:29 by nbelkaid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= lem-in
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
LFLAGS	= -L libft/ -lft
SRC_DIR	= ./srcs/
SRC		= lemin.c lemin2.c lemin3.c lemin4.c algo.c algo2.c algo3.c
VPATH	= $(SRC_DIR)
INC		= -I./includes -I./libft/includes
O_DIR	= ./obj
OBJ		= $(addprefix $(O_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	
	@echo "\033[1;32m"
	@echo "Lem-in"
	@make -C libft
	@echo "Link !"
	@$(CC) -o $(NAME) $^ $(LFLAGS)

$(O_DIR)/%.o: %.c
	@mkdir -p $(O_DIR)
	@printf "\033[1;34m."
	@$(CC) $(CFLAGS) -I ./includes -o $@ -c $<

clean:
	@echo "\033[1;34mDeleting Lem-in .o files."
	@rm -f $(OBJ)
	@rm -rf obj
	@make clean -C libft

fclean: clean
	@echo "\033[1;34mDeleting Lem-in."
	@rm -f $(NAME)
	@rm -rf obj
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
