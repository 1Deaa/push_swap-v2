#PROJECT
NAME = push_swap

#DIRECTORIES
FILES	=	main.c sort_util_a.c sort_util_b.c tiny_sort.c is_arranged.c find_highest.c \
			find_smallest.c ft_atoi.c handle_error.c list_util.c array_util.c big_sort.c

SRCS_DIR= src
SRCS	= $(addprefix $(SRCS_DIR)/, $(FILES))

#FLAGS
CFLAGS = -g -Wall -Wextra -Werror -I include
MAKEFLAGS += --no-print-directory

#COMMANDS
CC 	= cc
RM 	= rm -rf

#COLORS
DEF_COLOR = \e[1;39m
RESET = \e[0m
GRAY = \e[1;90m
RED = \e[1;91m
YELLOW = \e[1;93m
GREEN = \e[1;92m
BLUE = \e[1;94m
MAGENTA = \e[1;95m
CYAN = \e[1;96m
WHITE = \e[1;97m
BLINK = \e[5m

#OBJECT FILES
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ft_printf
	@echo "$(CYAN)█▀█ █ █ █▀ █ █ ▄▄ █▀ █ █ █ ▄▀█ █▀█"
	@echo "$(CYAN)█▀▀ █▄█ ▄█ █▀█    ▄█ ▀▄▀▄▀ █▀█ █▀▀"
	@$(CC) $(CFLAGS) $(OBJS) ft_printf/libftprintf.a -o $(NAME)
	@echo "$(GREEN)✔ $(MAGENTA)created $(GREEN)./push_swap $(MAGENTA)succesfully!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(WHITE)· $(YELLOW)compiling file: $(BLINK)○$(RESET)"

clean:
	@make -C ft_printf clean
	@$(RM) $(OBJS)

fclean:
	@make -C ft_printf fclean
	@$(RM) $(OBJS) $(NAME)

re: fclean all

.PHONY: all fclean clean re
