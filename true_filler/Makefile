# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/11 14:01:06 by ctestabu          #+#    #+#              #
#    Updated: 2019/04/11 15:46:51 by ctestabu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ctestabu.filler

FLAGS = -Wall -Werror -Wextra -g3
INC = -I ./incl/

### PATH ###
SRCS_PATH = srcs/
OBJ_PATH  = obj/
LIBFT_PATH = libft/

SRCS_NAME =	algo.c\
            figure.c\
            let_the_body_hit_the_floor.c\
            main.c\
            pars.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(SRCS_NAME:.c=.o))

### COMPILE ###
all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@gcc $(FLAGS) $(OBJ) $(INC) -L $(LIBFT_PATH) -lft -framework OpenGL -framework AppKit -lmlx -o $(NAME)
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
		@echo "\033[34m\033[1mCompilation of \033[0m\033[36m$(notdir $<)\033[1m\033[34m done.\033[0m"
		@mkdir -p `dirname $@`
		@gcc -c $(FLAGS) $(INC) $< -o $@

clean:
		@make -C $(LIBFT_PATH) fclean
		@/bin/rm -rf $(OBJ_PATH)
		@/bin/rm -rf filler.trace
		@/bin/rm -rf board.map
		@echo "\033[1;31m$(NAME) \033[1;0m\033[31mobjects files removed.\033[0m"

fclean: clean
		@/bin/rm -rf $(NAME)
		@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re