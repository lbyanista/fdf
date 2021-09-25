NAME = fdf
SRC = fdf.c
FLAGS = -Wall -Wextra -Werror -Imlx -lmlx -framework OpenGl -framework AppKit

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(SRC) -o $(NAME)

clean:
	@rm -rf *dSYM *.gch

fclean: clean
	@rm -rf $(NAME)

re: fclean all
