NAME_SERVER = server
NAME_CLIENT = client

NAME_SERVERB = server_bonus
NAME_CLIENTB = client_bonus

SRCS_CLIENT = client.c
SRCS_SERVER = server.c

OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}
OBJS_SERVER = ${SRCS_SERVER:.c=.o}

CC = gcc
RM = rm -f


all: client server

bonus: server_bonus client_bonus

server_bonus:
			${CC} server_bonus.c aux_functions.c libminitalk.h -o ${NAME_SERVERB}

client_bonus: 
		${CC} client_bonus.c aux_functions.c libminitalk.h -o ${NAME_CLIENTB}


client: 
		${CC} client.c aux_functions.c libminitalk.h -o ${NAME_CLIENT}

server: 
		${CC} server.c aux_functions.c libminitalk.h -o ${NAME_SERVER}

clean:
			${RM} ${OBJS_CLIENT} ${OBJS_SERVER} ${OBJS_CLIENTBONUS} ${OBJS_SERVERBONUS}

fclean: clean
			${RM} ${NAME_CLIENT} ${NAME_SERVER} ${NAME_CLIENTB} ${NAME_SERVERB}

re: fclean all

.PHONY: all clean fclean bonus
