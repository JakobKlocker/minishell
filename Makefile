NAME = minishell

SRC = main.c \
	builtins.c \
	builtins1.c \
	count_words.c \
	env_funcs.c \
	executer.c \
	expander_1.c \
	expander.c \
	export.c \
	export_utils.c \
	export_utils2.c \
	first_split.c \
	full_path.c \
	handle_forks.c \
	heredoc.c \
	main.c \
	prepare_nodes.c \
	remove_quotes.c \
	signal.c \
	utils.c \
	utils2.c \
	minishell.h \

OBJ = $(SRC:.c=.o)
CC = cc
FLAG = -Wall -Werror -Wextra
OPTION = -o -lreadline

all: $(NAME)

$(NAME):		
		$(MAKE) all -C ./libft
		$(CC) $(OPTION) $(SRC) -o $(NAME)

clean: 
		$(MAKE) clean -C ./libft
		rm -f *.o

fclean: clean
		$(MAKE) fclean -C ./libft
		rm -f *.o
		rm -f $(NAME)

re:		fclean all

bonus:	all

.PHONY: all bonus clean fclean re
