##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Remember when you want to be an architect ? Nope
##

SRC	=	main.c

NAME	=	102architect

all:	$(NAME)

$(NAME):
	make -C lib/my
	gcc -o $(NAME) $(SRC) -Llib/my -lmy -lm

clean:
	make -C lib/my clean

fclean:	clean
	make -C lib/my fclean
	rm $(NAME)

re:	fclean all
	make -C lib/my fclean
