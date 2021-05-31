##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile for day10
##

NAME		=		libmy.a

SRC			=		${wildcard *.c}

OBJ			=		${SRC:.c=.o}

RM			=		rm -rf

CC			=		gcc

all:	$(NAME)

${NAME}:	${OBJ}
	ar rc libmy.a ${OBJ}
	mv libmy.a ../

debug:	CFLAGS += -g

debug:	${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ../${NAME}

re:	fclean all

.PHONY:	all ${NAME} debug clean fclean re