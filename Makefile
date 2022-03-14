#=======================================#
#[MINITALK] Fonctions partie principale#
#=======================================#

CLIENT_SRC = client.c 

SERVER_SRC = server.c 

COMMON_SRC = check_pid.c panic_button.c ft_atoi.c ft_putnbr.c
				
COMMON_OBJ = ${addprefix ${OBJDIR}, ${COMMON_SRC:%.c=%.o}}

CLIENT_OBJ = ${addprefix ${OBJDIR}, ${CLIENT_SRC:%.c=%.o}} ${COMMON_OBJ}

SERVER_OBJ = ${addprefix ${OBJDIR}, ${SERVER_SRC:%.c=%.o}} ${COMMON_OBJ}

#====#
#Tags#
#====#

OBJDIR = ./objs/
SERVERDIR = ./src_server/
CLIENTDIR = ./src_client/
COMMONDIR = ./common/
INCLUDES = ./includes/
NAME_CLIENT = client
NAME = server
CFLAGS = -Wall -Wextra -Werror ${SANIFLAG}
SANIFLAG = -fsanitize=address -g


#=========#
#Commandes#
#=========#					

${OBJDIR}%.o : ${SERVERDIR}%.c
								@gcc ${CFLAGS} -c $< -o $@ -I ${INCLUDES}

${OBJDIR}%.o : ${CLIENTDIR}%.c
								@gcc ${CFLAGS} -c $< -o $@ -I ${INCLUDES}

${OBJDIR}%.o : ${COMMONDIR}%.c
								@gcc ${CFLAGS} -c $< -o $@ -I ${INCLUDES}

${NAME}: 						${NAME_CLIENT} ${OBJDIR} ${SERVER_OBJ}
								@gcc ${CFLAGS} ${SERVER_OBJ} -o ${NAME}
								@printf "\e[32;3m$@ successfully build\e[0m\n"

${NAME_CLIENT}:					${OBJDIR} ${CLIENT_OBJ}
								@gcc ${CFLAGS} ${CLIENT_OBJ} -o ${NAME_CLIENT}
								@printf "\e[32;3m$@ successfully build\e[0m\n"

${OBJDIR}:						
								@mkdir -p ${OBJDIR}

all:							${NAME}
								

clean:
								@rm -rf ${OBJDIR}
								@printf "\e[31;3mClean files\e[0m\n"

fclean:							clean
								@rm -f ${NAME}
								@rm -f ${NAME_CLIENT}
								@printf "\e[31;3mClean execs\e[0m\n"

re:								fclean all

.PHONY:							all clean fclean re