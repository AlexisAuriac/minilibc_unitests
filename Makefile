##
## EPITECH PROJECT, 2018
## minilibc
## File description:
## Makefile for unitests.
##

SRC_UT	=	test_strlen.c		\
			test_strchr.c		\
			test_memset.c		\
			test_memcpy.c		\
			test_strcmp.c		\
			test_memmove.c		\
			test_strncmp.c		\
			test_strcasecmp.c	\
			test_rindex.c		\
			test_strstr.c		\
			test_strpbrk.c		\
			test_strcspn.c

SRC_UT	:=	$(addprefix tests/, $(SRC_UT))

OBJ		=	$(SRC:.asm=.o)		\
			$(SRC_UT:.c=.o)

CFLAGS	+=	-Wall -Wextra --coverage -DLIB=\"../libasm.so\"

LDFLAGS	+=	-ldl -lcriterion -lgcov

LIB		=	libasm.so

NAME	=	units

all:	$(NAME)

$(LIB):
	make $(LIB) -C ../

$(NAME): $(OBJ) $(LIB)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
		./$(NAME)

clean:
		$(RM) $(OBJ)
		$(RM) $(SRC_UT:.c=.gcda)
		$(RM) $(SRC_UT:.c=.gcno)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all lib clean fclean re
