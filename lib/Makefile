##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## this is the makefile to create the libraries
##

NAME		=		make_lib

all:	${NAME}

${NAME}:
	make -C my
	make -C my_printf

debug:
	make debug -C my
	make debug -C my_printf

clean:
	make clean -C my
	make clean -C my_printf

fclean:
	make fclean -C my
	make fclean -C my_printf

re:	fclean ${NAME}

.PHONY:	all ${NAME} debug clean fclean re