##
## EPITECH PROJECT, 2022
## Cpool
## File description:
## Makefile
##

SRC	=	$(wildcard ./source/*.c) $(wildcard ./bonus/*.c)

CFLAGS	=

OBJ	=	$(SRC:.c=.o)

LIB	=	lib$(NAME).a

NAME = my_hunter

all:	$(LIB)

$(LIB):	$(OBJ)
	ar rc $(LIB) $(OBJ)
	gcc main.c -o $(NAME) -L. -l$(NAME) -lcsfml-graphics -lcsfml-system \
	-lcsfml-window -lcsfml-audio -lm -I include $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(LIB)
	rm -f $(NAME)

re: fclean all

cpl: re
	make clean

run: cpl
	./$(NAME)
