##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## this is the makefile for matchstick
##

NAME		=		matchstick

NAMET		=		${NAME}_tests

NAMEB		=		${NAME}_bonus

NAMES		=		server

SRC_PATH	=		src

TEST_PATH	=		tests

BONUS_PATH	=		bonus/src

SRC			=		${SRC_PATH}/main.c                          \
					${SRC_PATH}/error_handling.c                \
					${SRC_PATH}/load_map.c                      \
					${SRC_PATH}/check_win.c                     \
					${SRC_PATH}/check_input.c                   \
					${SRC_PATH}/game_loop.c                     \
					${SRC_PATH}/remove_sticks.c            		\
					${SRC_PATH}/artifical_inteligence.c         \
					${SRC_PATH}/get_sticks.c               		\
					${SRC_PATH}/get_input.c                     \
					${SRC_PATH}/create_game_tools.c             \

SRCT		=		${TEST_PATH}/tests.c                        \
					${SRC_PATH}/error_handling.c                \
					${SRC_PATH}/load_map.c                      \
					${SRC_PATH}/check_win.c                     \
					${SRC_PATH}/check_input.c                   \
					${SRC_PATH}/remove_sticks.c            		\
					${SRC_PATH}/get_sticks.c               		\
					${SRC_PATH}/get_input.c                     \
					${SRC_PATH}/create_game_tools.c				\

SRCB		=		${BONUS_PATH}/main.c                          \
					${BONUS_PATH}/error_handling.c                \
					${BONUS_PATH}/load_map.c                      \
					${BONUS_PATH}/check_win.c                     \
					${BONUS_PATH}/check_input.c                   \
					${BONUS_PATH}/gamemodes.c                     \
					${BONUS_PATH}/remove_sticks.c            	  \
					${BONUS_PATH}/artifical_inteligence_strong.c  \
					${BONUS_PATH}/artifical_inteligence_medium.c  \
					${BONUS_PATH}/artifical_inteligence_low.c     \
					${BONUS_PATH}/artifical_inteligence_low_low.c \
					${BONUS_PATH}/get_sticks.c               	  \
					${BONUS_PATH}/get_input.c                     \
					${BONUS_PATH}/create_game_tools.c             \
					${BONUS_PATH}/usage.c                         \
					${BONUS_PATH}/player_ia_turn.c                \
					${BONUS_PATH}/player_player.c                 \

SRCS		=		${BONUS_PATH}/server.c

OBJ			=		${SRC:.c=.o}

OBJT		=		${SRCT:.c=.o}

OBJB		=		${SRCB:.c=.o}

OBJS		=		${SRCS:.c=.o}

RM			=		rm -rf

CFLAGS		=		 -Wall -Wextra

CPPFLAGS	=		-I./includes

LDFLAGS		=		-L./lib

LDLIBS		=		-lmy -lmy_printf

CC			=		gcc

all:	${NAME}

${NAME}:	${OBJ} make_lib
	${CC} -o ${NAME} ${OBJ} ${LDFLAGS} ${LDLIBS}

bonus:	CPPFLAGS = -I./bonus/includes

bonus: CFLAGS += -g

bonus: ${OBJB} ${OBJS} make_lib
	${CC} -o ${NAMEB} ${OBJB} ${LDFLAGS} ${LDLIBS}
	${CC} -o ${NAMES} ${OBJS}

debug:	CFLAGS += -g

debug:	${OBJ} make_debug_lib
	${CC} -o ${NAME} ${OBJ} ${LDFLAGS} ${LDLIBS}

make_debug_lib:
	make debug -C lib

make_lib:
	make -C lib

clean:
	${RM} ${OBJ}
	${RM} ${OBJT}
	${RM} ${OBJB}
	${RM} ${OBJS}
	make clean -C lib

fclean:	clean
	${RM} ${NAME}
	${RM} ${NAMET} ${TEST_PATH}/*.gc* ${SRC_PATH}/*.gc*
	${RM} ${NAMEB}
	${RM} ${NAMES}
	make fclean -C lib

re:	fclean	${NAME}

unit_test:	CFLAGS += -fprofile-arcs -ftest-coverage

unit_test:	LDLIBS += -lcriterion -lgcov

unit_test:	${OBJT} make_lib
	${CC} -o ${NAMET} ${OBJT} ${LDFLAGS} ${LDLIBS}

tests_run:	unit_test
	./${NAMET}

coverage:
	gcovr --exclude tests

branches:
	gcovr --branches --exclude tests

.PHONY:	all ${NAME} make_lib clean fclean re unit_test tests_run
.PHONY:	coverage branches bonus
