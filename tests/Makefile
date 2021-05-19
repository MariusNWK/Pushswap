##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## projet solo 1
##

SRC     =       $(wildcard *.c)

OBJ     =       $(SRC:.c=.o)

NAME	=	push_swap

CFLAGS	=	-I ./include/

all:	$(OBJ)
	$(MAKE) -C ./lib/my/
	$(CC) -g -o $(NAME) $(OBJ) lib/my/libmy.a $(CFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) ./lib/my/*~
	$(RM) $(NAME)
	$(MAKE) -C ./lib/my/ clean

fclean:	clean
	$(RM) lib/libmy.a
	$(MAKE) -C ./lib/my/ fclean

re:	fclean all

.Phony: all clean fclean re
