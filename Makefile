# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 17:40:25 by gcredibl          #+#    #+#              #
#    Updated: 2021/11/13 17:40:25 by gcredibl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLI_DIR		= cli/

CLICL_DIR	= ${CLI_DIR}cli_class/
CLICL_SRCS	= cli_readline.c cli_init.c
CLICL_SRCS	:= $(addprefix ${CLICL_DIR}, ${CLICL_SRCS})

LINE_DIR	= ${CLI_DIR}line_class/
LINE_SRCS	= line.c line_init.c
LINE_SRCS	:= $(addprefix ${LINE_DIR}, ${LINE_SRCS})

HNODE_DIR	= ${CLI_DIR}hist_node_class/
HNODE_SRCS	= hist_node.c
HNODE_SRCS	:= $(addprefix ${HNODE_DIR}, ${HNODE_SRCS})

MAIN_DIR	= main/
MAIN_SRCS	= main.c signals.c
MAIN_SRCS	:= $(addprefix ${MAIN_DIR}, ${MAIN_SRCS})

ERRORS_DIR	= errors/
ERRORS_SRCS	= process_errors.c
ERRORS_SRCS	:= $(addprefix ${ERRORS_DIR}, ${ERRORS_SRCS})

PARSE_DIR	= parser/
PARSE_SRCS	= parser.c token.c lexer.c lexer_get_token.c check_symbol.c lexer_quotes.c lexer_check_grammar.c lexer_token_type.c parser_make_jobs.c job.c token_prepare.c
PARSE_SRCS	:= $(addprefix ${PARSE_DIR}, ${PARSE_SRCS})

EXEC_DIR	= exec/
EXEC_SRCS	= exec.c env_p1.c env_p2.c env_p3.c path.c utils_p1.c utils_p2.c pipes.c redirects.c
EXEC_SRCS	:= $(addprefix ${EXEC_DIR}, ${EXEC_SRCS})

EXEC_BUILTIN_DIR	= exec/builtins/
EXEC_BUILTIN_SRCS	= index.c export.c unset.c pwd.c env.c cd.c echo.c exit.c
EXEC_BUILTIN_SRCS	:= $(addprefix ${EXEC_BUILTIN_DIR}, ${EXEC_BUILTIN_SRCS})

SRCS		= ${MAIN_SRCS} ${CLICL_SRCS} ${LINE_SRCS} ${HNODE_SRCS} ${ERRORS_SRCS} ${PARSE_SRCS} ${EXEC_SRCS} ${EXEC_BUILTIN_SRCS}

#HEADERS		= minishell.h

OBJS		= ${SRCS:.c=.o}

NAME		= minishell

LIBFT_DIR	= libft/

LIBFT		= libft.a

INCLUDES	= -I${LIBFT_DIR} -I${CLICL_DIR} -I${MAIN_DIR} -I${LINE_DIR} -I${HNODE_DIR} -I${ERRORS_DIR} -I${PARSE_DIR} -I${EXEC_DIR}

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

%.o:		%.c 
			${CC} ${CFLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${LIBFT_DIR}${LIBFT} ${OBJS}
			${CC} ${OBJS} ${INCLUDES} -L${LIBFT_DIR} -lft ${MLXFLAGS} -o ${NAME} -ltermcap

debug:		${LIBFT_DIR}${LIBFT} ${OBJS}
			${CC} -ggdb ${OBJS} ${INCLUDES} -L${LIBFT_DIR} -lft ${MLXFLAGS} -o ${NAME} -ltermcap -fsanitize=address -fno-omit-frame-pointer

${LIBFT_DIR}${LIBFT}:	${LIBFT_DIR}
			${MAKE} -C ${LIBFT_DIR} bonus

bonus:		${NAME}

clean:
			${RM} ${OBJS}
			${MAKE} -C ${LIBFT_DIR} clean

fclean:		clean
			${RM} ${NAME}
			${MAKE} -C ${LIBFT_DIR} fclean
#			cd libft && ${MAKE} fclean

re:			fclean all

.PHONY:		all clean fclean re
