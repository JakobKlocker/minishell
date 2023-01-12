NAME = minishell
SRC = main.c \
OBJ = $(SRC:.c=.o)
CC = cc
FLAG = -Wall -Werror -Wextra
OPTION = -o

all: $(NAME)

$(NAME):
		$(MAKE) all -C ./libft
		$(CC) $(OPTION) $(NAME) $(FLAG) $(SRC) libft/libft.a

clean: 
		$(MAKE) clean -C ./libft
		rm -f $(OBJ)

fclean: clean
		$(MAKE) fclean -C ./libft
		rm -f $(NAME)

re:		fclean all

bonus:	all

.PHONY: all bonus clean fclean re
