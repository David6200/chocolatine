##
## EPITECH PROJECT, 2025
## makefile
## File description:
## makefile
##

CC          = clang

SRC         = SRC/amazed.c		\
			SRC/bfs.c		\
			SRC/check_room.c	\
			SRC/dear_optimal_path.c	\
			SRC/display.c		\
			SRC/error_case.c	\
			SRC/link.c		\
			SRC/mini_printf.c	\
			SRC/my_get_nbr.c	\
			SRC/my_put_nbr.c	\
			SRC/my_putchar.c	\
			SRC/my_putstr.c		\
			SRC/my_strcmp.c		\
			SRC/my_strdup.c		\
			SRC/my_strlen.c		\
			SRC/my_strstr.c		\
			SRC/my_strtok.c		\

TEST_SRC	= SRC/my_strcmp.c	\
			SRC/my_putchar.c	\
			SRC/my_putstr.c		\
			SRC/my_put_nbr.c	\
			SRC/mini_printf.c	\
			SRC/my_strdup.c		\
			SRC/my_strlen.c		\
			SRC/my_strtok.c		\
			SRC/my_get_nbr.c	\

TEST        = tests/unit_test.c
NAME        = amazed
TEST_NAME   = unit_tests

all: $(NAME)

$(NAME):
	$(CC) $(SRC) -o $(NAME) -g3

tests_run: fclean
	$(CC) $(TEST_SRC) $(TEST) -o $(TEST_NAME) \
		-lcriterion -g3 --coverage -I./SRC
	./$(TEST_NAME)

clean:
	rm -f *.o
	rm -f SRC/*.o
	rm -f tests/*.o
	rm -f *.gcda
	rm -f *.gcno

fclean: clean
	rm -f $(NAME)
	rm -f $(TEST_NAME)

re: fclean all
