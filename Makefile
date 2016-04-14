# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bndao <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/14 05:31:21 by bndao             #+#    #+#              #
#    Updated: 2016/04/14 07:19:59 by bndao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FLAGS = -Wall
FLAGS += -Werror
FLAGS += -Wextra

SRCDIR = src/

SRC = $(SRCDIR)push_swap.c \
		$(SRCDIR)lst.c \
		$(SRCDIR)utils.c \

INC = header

OBJ = $(SRC:.c=.o)

all: lib $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -I $(INC) -L ./libft -lftprintf
	@echo "\033[1;31m---- Push_Swap Created !!! ----\033[0m"

%.o:%.c
	@gcc $(FLAGS) -c -o $@ $< -I $(INC) -I libft/

lib:
	@echo "\033[1;32m-> Creating Library...\033[0m"
	@make -C ./libft/

clean:
	@rm -f $(OBJ)
	@echo "\033[0;36m\nDirectory Cleaned up.\033[0m"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft/

re: fclean all

allclean: re clean

.PHONY: $(NAME) all lib clean fclean re allclean
