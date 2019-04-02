##
## EPITECH PROJECT, 2018
## makefile
## File description:
## lib
##

SRC	=	$(wildcard src/*.c)

NAME	=	conway

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -lncurses -I include/

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:	
		rm -f $(OBJ)
		rm -rf *~
		rm -rf src/*~

fclean:		clean
		rm -f $(NAME)

re:		fclean all
