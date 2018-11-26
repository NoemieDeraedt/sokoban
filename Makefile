##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

LIB	=	$(wildcard lib/my/*.c)

SRC	=	$(wildcard *.c)

OBJ	=	$(LIB:.c=.o)

NAME	=	test

BINARY	=	my_sokoban

CFLAGS	=	-W -Wall -Wextra

all: $(NAME) clean $(BINARY)

$(NAME):	$(OBJ) lib
	gcc -o $(NAME) $(OBJ)

lib:		$(OBJ)
	ar rc libmy.a $(OBJ)

$(BINARY):	$(SRC)
	gcc -o $(BINARY) $(SRC) -L./ -lmy -lncurses $(CFLAGS)

clean:
	rm -f $(OBJ) $(NAME)

fclean: clean
	rm -f $(NAME)

re:	fclean all
