# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 20:39:07 by astridgault       #+#    #+#              #
#    Updated: 2021/07/08 01:13:38 by asgaulti@st      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER	=	./server/server

CLIENT	=	./client/client

SRCS_SERVER	= ./server/ft_server.c ./server/ft_utils.c

SRCS_CLIENT	= ./client/ft_client.c ./client/ft_utils.c

OBJS_SERVER	=	${SRCS_SERVER:.c=.o}

OBJS_CLIENT	=	${SRCS_CLIENT:.c=.o}

CC		=	clang-9
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra

INCL	=	include

.c.o:
			${CC} ${CFLAGS} -I${INCL} -g -c $< -o ${<:.c=.o}

all:		${SERVER} ${CLIENT}

$(SERVER):	${OBJS_SERVER}
			${CC} ${CFLAGS} -o ${SERVER} ${OBJS_SERVER}

$(CLIENT):	${OBJS_CLIENT}
			${CC} ${CFLAGS} -o ${CLIENT} ${OBJS_CLIENT}

clean:
			${RM} ${OBJS_SERVER} ${OBJS_CLIENT} $(SERVER) $(CLIENT)

fclean:		clean
			${RM} ${OBJS_SERVER} ${OBJS_CLIENT} $(SERVER) $(CLIENT)
					
re:			fclean all

.PHONY:		all clean fclean re