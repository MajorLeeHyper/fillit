NAME		= fillit
LIB			= libfil.a
FILENAMES	= ft_get_tetro.c ft_checks.c ft_dance.c ft_table.c ft_solve.c main.c ft_pieces0.c ft_pieces1.c ft_pieces2.c ft_ofs_len.c ft_dance1.c
HEADER		= .
FLAGS		= -Wall -Wextra -Werror
TEST		= runtest

SRC			= $($(FILENAMES))
OBJ			= $(addprefix build/, $(FILENAMES:.c=.o))

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(LIB)
	gcc $(FLAGS) -I. -I libft libft/libft.a $(LIB) -o $(NAME)

$(LIB): $(OBJ)
	ar rc $(LIB) $(OBJ) 
	make -C libft

build/%.o: %.c | build
	gcc $(FLAGS) -I $(HEADER) -I libft -I. -c $^ -o $@

build:
	mkdir build

clean:
	rm -rf build
	rm -f runme
	rm -f libfil.a
	make fclean -C libft

fclean: clean
	rm -f $(NAME)

re: fclean all
