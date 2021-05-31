##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile for bistromatic
##

NAME    	=       libmy_printf.a

SRC_PATH	=		src

SRC     	=  		${SRC_PATH}/my_printf.c                \
					${SRC_PATH}/my_compute_power_rec.c     \
					${SRC_PATH}/my_octal.c                 \
					${SRC_PATH}/my_hexadecimal.c           \
					${SRC_PATH}/my_getnbr.c                \
					${SRC_PATH}/my_putchar.c       		   \
					${SRC_PATH}/my_put_nbr.c               \
					${SRC_PATH}/my_revstr.c                \
					${SRC_PATH}/my_putstr.c                \
					${SRC_PATH}/my_strlen.c                \
					${SRC_PATH}/my_strdup.c                \
					${SRC_PATH}/my_strcpy.c                \
					${SRC_PATH}/my_intlen.c                \
					${SRC_PATH}/my_str_change.c            \
					${SRC_PATH}/wrapper_binary.c           \
					${SRC_PATH}/wrapper_character.c        \
					${SRC_PATH}/wrapper_hexadecimal.c      \
					${SRC_PATH}/wrapper_hexadecimal_up.c   \
					${SRC_PATH}/wrapper_integrer.c         \
					${SRC_PATH}/wrapper_octal.c            \
					${SRC_PATH}/wrapper_pointer.c          \
					${SRC_PATH}/wrapper_porcentage.c       \
					${SRC_PATH}/wrapper_string.c           \
					${SRC_PATH}/wrapper_my_showstr.c       \
					${SRC_PATH}/wrapper_unsigned_int.c

OBJ     	=       ${SRC:.c=.o}

RM			=		rm -rf

CPPFLAGS	=		-I./includes

CC			=		gcc

all:    ${NAME}

${NAME}:        ${OBJ}
	ar rc ${NAME} ${OBJ}
	mv ${NAME} ../

debug:	CFLAGS += -g

debug:	${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ../${NAME}

re:     fclean ${NAME}

.PHONY:	all ${NAME} debug clean fclean re