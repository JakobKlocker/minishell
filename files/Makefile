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
	prepare_nodes.c \
	prepare_nodes_1.c \
	prepare_nodes_2.c \
	remove_quotes.c \
	signal.c \
	utils.c \
	utils2.c \
	free.c \
	inc_shlvl.c \
	builtins_fork.c \
	our_exit_builtin.c \

OBJ = $(SRC:.c=.o)
CC = cc
FLAG = -Wall -Werror -Wextra
OPTION = -o

all: $(NAME)

$(NAME):		
		$(MAKE) all -C ./libft
		$(CC) $(FLAG) $(OPTION) $(NAME) $(SRC) libft/libft.a -lreadline

run: 
	$(MAKE) all -C ./libft
	$(MAKE) re
	$(CC) $(FLAG) $(OPTION) $(NAME) $(SRC) libft/libft.a -lreadline && ./$(NAME)

val: all
	make -C ./ clean
	valgrind --leak-check=full \
	--show-leak-kinds=all \
	--track-origins=yes \
	--verbose \
	--log-file=valgrind-out.txt \
		./$(NAME)

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
