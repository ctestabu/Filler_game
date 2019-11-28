NAME = libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra -c
INCLUDES = -I$(HEADERS_DIRECTORY)
HEADERS_LIST = \
	libft.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))
SOURCES_DIRECTORY = ./srcs/
SOURCES_LIST = ft_atoi.c\
                                    ft_bzero.c\
                                    ft_countnbr.c\
                                    ft_countunbr.c\
                                    ft_intlen.c\
                                    ft_isalnum.c\
                                    ft_isalpha.c\
                                    ft_isascii.c\
                                    ft_isdigit.c\
                                    ft_islower.c\
                                    ft_isprint.c\
                                    ft_isupper.c\
                                    ft_itoa.c\
                                    ft_itoabase.c\
                                    ft_itoabaseu.c\
                                    ft_lstadd.c\
                                    ft_lstdel.c\
                                    ft_lstdelone.c\
                                    ft_lstiter.c\
                                    ft_lstmap.c\
                                    ft_lstnew.c\
                                    ft_memalloc.c\
                                    ft_memccpy.c\
                                    ft_memchr.c\
                                    ft_memcmp.c\
                                    ft_memcpy.c\
                                    ft_memdel.c\
                                    ft_memmove.c\
                                    ft_memset.c\
                                    ft_putchar.c\
                                    ft_putchar_fd.c\
                                    ft_putendl.c\
                                    ft_putendl_fd.c\
                                    ft_putnbr.c\
                                    ft_putnbr_fd.c\
                                    ft_putnbrwp.c\
                                    ft_putnstr.c\
                                    ft_putstr.c\
                                    ft_putstr_fd.c\
                                    ft_putstrwp.c\
                                    ft_putunbr.c\
                                    ft_putunbrwp.c\
                                    ft_putzerox.c\
                                    ft_strcat.c\
                                    ft_strchr.c\
                                    ft_strclr.c\
                                    ft_strcmp.c\
                                    ft_strcpy.c\
                                    ft_strdel.c\
                                    ft_strdup.c\
                                    ft_strequ.c\
                                    ft_striter.c\
                                    ft_striteri.c\
                                    ft_strjoin.c\
                                    ft_strlcat.c\
                                    ft_strlen.c\
                                    ft_strmap.c\
                                    ft_strmapi.c\
                                    ft_strncat.c\
                                    ft_strncmp.c\
                                    ft_strncpy.c\
                                    ft_strndup.c\
                                    ft_strnequ.c\
                                    ft_strnew.c\
                                    ft_strnstr.c\
                                    ft_strrchr.c\
                                    ft_strsplit.c\
                                    ft_strstr.c\
                                    ft_strsub.c\
                                    ft_strtrim.c\
                                    ft_tolower.c\
                                    ft_toupper.c\
                                    get_next_line.c

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))
OBJECTS_DIRECTORY = obj/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

# MAKEFLAGS += -j

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

clean:
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all