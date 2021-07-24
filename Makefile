# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 20:39:07 by astridgault       #+#    #+#              #
#    Updated: 2021/07/23 16:19:22 by asgaulti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERVER	=	./server/server

CLIENT	=	./client/client

SRCS_SERVER	= ./server/ft_server.c ./server/ft_utils.c

SRCS_CLIENT	= ./client/ft_client.c ./client/ft_utils.c

OBJS_SERVER	=	${SRCS_SERVER:.c=.o}
DEP_SERVER	=	${SRCS_SERVER:.c=.d}

OBJS_CLIENT	=	${SRCS_CLIENT:.c=.o}
DEP_CLIENT	=	${SRCS_CLIENT:.c=.d}

CC		=	clang-9
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra -MMD

INCL	=	include

all:		${NAME}

$(NAME):	${SERVER} ${CLIENT}

$(SERVER):	${OBJS_SERVER}
			${CC} ${CFLAGS} -o ${SERVER} ${OBJS_SERVER}

$(CLIENT):	${OBJS_CLIENT}
			${CC} ${CFLAGS} -o ${CLIENT} ${OBJS_CLIENT}

-include ${DEP_SERVER} ${DEP_CLIENT}

.c.o:
			${CC} ${CFLAGS} -I${INCL} -g -c $< -o ${<:.c=.o}

clean:
			${RM} ${DEP_SERVER} ${DEP_CLIENT} ${OBJS_SERVER} ${OBJS_CLIENT}

fclean:		clean
			${RM} $(SERVER) $(CLIENT)
					
re:			fclean all

.PHONY:		all clean fclean re minitalk
