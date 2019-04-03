##
## EPITECH PROJECT, 2018
## makefile
## File description:
## lib
##

SRC_CONWAY	=	$(wildcard src/simulation/*.c)
SRC_CREATOR	=	$(wildcard src/creator/*.c)

NAME_CONWAY	=	conway
NAME_CREATOR =	creator

OBJ_CONWAY	=	$(SRC_CONWAY:.c=.o)
OBJ_CREATOR	=	$(SRC_CREATOR:.c=.o)

CFLAGS	=	-W -Wall -Wextra -lncurses -I include/

all:		$(NAME_CONWAY) $(NAME_CREATOR)

$(NAME_CONWAY):	$(OBJ_CONWAY)
				gcc -o $(NAME_CONWAY) $(OBJ_CONWAY) $(CFLAGS)
$(NAME_CREATOR):	$(OBJ_CREATOR)
				gcc -o $(NAME_CREATOR) $(OBJ_CREATOR) $(CFLAGS)

clean:	
		rm -f $(OBJ_CONWAY)
		rm -f $(OBJ_CREATOR)
		rm -rf *~
		rm -rf src/simulation/*~
		rm -rf src/creator/*~

fclean:		clean
		rm -f $(NAME_CONWAY)
		rm -f $(NAME_CREATOR)

re:		fclean all
