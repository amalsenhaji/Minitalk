# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amsenhaj <amsenhaj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/19 05:03:03 by amsenhaj          #+#    #+#              #
#    Updated: 2022/02/21 02:55:34 by amsenhaj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES	= server.c client.c minitalk_utils.c
OFILES	= ${CFILES:.c=.o}
BCFILES = server_bonus.c client_bonus.c minitalk_utils_bonus.c
BOFILES = ${BCFILES:.c=.o}
CLIENT	= client
SERVER 	= server
CLIENT_BONUS	= client_bonus
SERVER _BONUS	= server_bonus
CC		= @cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= minitalk.a
NAME_BONUS = minitalk_bonus.a
RM		= rm -rf

all				:	${SERVER} ${CLIENT}

${SERVER}		: ${NAME} minitalk.h
	@${CC} ${CFLAGS} ${NAME} server.c -o ${SERVER}

${CLIENT}		: ${NAME} minitalk.h
	@${CC} ${CFLAGS} ${NAME} client.c -o ${CLIENT}

bonus			: ${SERVER _BONUS} ${CLIENT_BONUS}

${SERVER _BONUS}	: ${NAME_BONUS} minitalk_bonus.h
	@${CC} ${CFLAGS} ${NAME_BONUS} server_bonus.c -o ${SERVER _BONUS}

${CLIENT_BONUS}	: ${NAME_BONUS} minitalk_bonus.h
	@${CC} ${CFLAGS} ${NAME_BONUS} client_bonus.c -o ${CLIENT_BONUS}

${NAME}			: ${OFILES}
	@ar -cr ${NAME} ${OFILES}
	@echo "\033[92mDone for Minitalk\033[0m"

${NAME_BONUS}	: ${BOFILES}
	@ar -cr ${NAME_BONUS} ${BOFILES}
	@echo "\033[92mDone for Minitalk_bonus\033[0m"

clean :
	@${RM} ${OFILES} ${BOFILES}
	@echo "\033[92mClean Success\033[0m"

fclean			: clean
	@${RM} ${NAME} ${NAME_BONUS}
	@${RM} ${SERVER } ${CLIENT}
	@${RM} ${SERVER _BONUS} ${CLIENT_BONUS}
	@echo "\033[92mFclean Success\033[0m"

re 				: fclean all
