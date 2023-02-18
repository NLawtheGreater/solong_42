# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 13:59:17 by niclaw            #+#    #+#              #
#    Updated: 2023/02/19 00:56:04 by niclaw           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### EXECUTABLE ###
# This is where you want to put the name of your program or library that you will be compiling

NAME	= so_long

### DIR ###
# all the dir to neatly keep your .c and .h

SRC_DIR		= srcs/
BONUS_DIR	= bonus/
HEAD		= include/
SHARE_DIR	= share/
LIB_DIR		= libft/
PRINT_DIR	= ft_printf/
BUILD =	./build/

### TESTER GIT URL ###
# add some git url to your makefile to make your evaluator life easier

TESTER1		=
TESTER2		=
TESTER3		=
TESTER4		=

### SO_LONG SPECIAL ###

UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
	PLATFORM_SRC = game_Linux.c
	MLX_DIR		= mlx_Linux
	MLX_FLAGS	= -L${MLX_DIR} -lmlx_Linux -lXext -lX11 -lm -lz
	INCLUDES 	= -I$(HEAD) \
				  -I$(LIB_DIR) \
				  -I$(PRINT_DIR)\
				  -I/usr/include\
				  -I${MLX_DIR}
	LIBS		= -L$(LIB_DIR) -lft \
				  -L/usr/lib 
else
	PLATFORM_SRC = game_Macos.c
	MLX_DIR		= mlx_opengl
	MLX_FLAGS	= -L${MLX_DIR} -lmlx -lm -lz\
				  -framework OpenGL \
				  -framework AppKit
	INCLUDES 	= -I$(HEAD) \
				  -I$(LIB_DIR) \
				  -I$(PRINT_DIR)\
				  -I$(MLX_DIR)
	LIBS		= -L$(LIB_DIR) -lft\
	
endif

### SOURCE FILE ###
# the name of your .c go here. SRC is for mandatory, BONUS is for the bonus. 
# SHARE is for .c file that your mandatory and bonus use. LIBFT is where your specific libft .c file go.

SRC	=	$(PLATFORM_SRC) fill.c init.c main.c map.c panel.c player.c\
		validate.c utils/file_util.c utils/game_util.c\
		utils/img_util.c utils/tile_util.c utils/vector_util.c 

BONUS	=	

SHARE	=

### PATH ###
# DO NOT CHANGE
SRCS		= ${addprefix ${SRC_DIR}, ${SRC}}
BONUS_SRCS	= ${addprefix ${BONUS_DIR}, ${BONUS}}
SHARE_SRCS	= ${addprefix ${SHARE_DIR}, ${SHARE}}

### OBJECT FILE ###
# DO NOT CHANGE
OBJS		= ${SRCS:.c=.o}
BONUS_OBJS	= ${BONUS_SRCS:.c=.o}
SHARE_OBJS	= ${SHARE_SRCS:.c=.o}

## LIBFT TARGET ##
LIBFT	= ${LIB_DIR}libft.a
PRINT	= ${PRINT_DIR}libftprintf.a

### COMPILATION ###
# the compilation flag that will we will use for the project

CC	= gcc
CFLAGS	= -g -Wall -Wextra -Wextra
RM	= rm -f

### COLORS ###
# up to your creativity 
NOC		= \033[0m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
WHITE	= \033[1;37m

### TMP ###
# if needed
MSG = "Upload to git"


### RULES ###
.c.o:	build ${SRCS} 
	@mkdir -p ${addprefix ${BUILD}, ${SRC_DIR}}
	@mkdir -p ${addprefix ${BUILD}, ${SRC_DIR}/utils}
	@mkdir -p ${addprefix ${BUILD}, ${SHARE_DIR}}
	@mkdir -p ${addprefix ${BUILD}, ${BONUS_DIR}}
	@echo "Build done!"
	${CC} ${CFLAGS} $(INCLUDES) \
	 -c $< -o ${addprefix ${BUILD}, ${<:.c=.o}}
	
build: 
	@mkdir -p ${addprefix ${BUILD}, ${SRC_DIR}}
	@mkdir -p ${addprefix ${BUILD}, ${SRC_DIR}/utils}
	@mkdir -p ${addprefix ${BUILD}, ${SHARE_DIR}}
	@mkdir -p ${addprefix ${BUILD}, ${BONUS_DIR}}
	@echo "Build done!"
	

${NAME}:	${OBJS} ${SHARE_OBJS} ${LIB_DIR} $(MLX_DIR)
	make -C ${LIB_DIR}
	make -C ${MLX_DIR}	 
	${CC} ${CFLAGS} ${addprefix ${BUILD}, ${OBJS}} ${addprefix ${BUILD}, ${SHARE_OBJS}}\
	 ${LIBS} $(MLX_FLAGS) -o ${NAME}
	@echo "$(GREEN) $@ Linking done!$(NOC)" 


all: ${NAME}

libs:
	make -C ${LIB_DIR}
	make -C ${MLX_DIR}
	make -C ${PRINT_DIR}

bonus:	${BONUS_OBJS} ${SHARE_OBJS} ${LIBFT}
	@${CC} ${CFLAGS} ${addprefix ${BUILD}, ${BONUS_OBJS}} ${addprefix ${BUILD}, ${SHARE_OBJS}}\
	${LIBFT} -o ${BONUS_NAME}
	@echo "$(GREEN)${BONUS_NAME}$(NOC)"

clean:
	@echo "$(RED)clean$(NOC)"
	make clean -C ${LIB_DIR} 
	make clean -C ${MLX_DIR} 
	${RM} -r ${BUILD}

fclean:	clean
	@echo "$(RED)fclean$(NOC)"
	make fclean -C ${LIB_DIR} 
	make clean -C ${MLX_DIR} 
	${RM} ${NAME} ${BONUS_NAME}

re:	fclean all

test2:

mem:	
#leaks --atExit -- ./$(NAME) $(MAP)
	valgrind --leak-check=full  --show-leak-kinds=all ./$(NAME) $(MAP)

MAP = "test5.ber"

tester:

norm:
	norminette

gitpush:
	git add .
	git status
	git commit -m "${MSG}"
	git push

help:
	@clear
	@echo "$(GREEN)Avaibles options:$(NOC)"
	@echo "$(RED)==================$(NOC)"
	@echo "$(RED)| $(YELLOW)make ${NAME} $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make bonus     $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make norm      $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make tester    $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make clean     $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make fclean    $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make re        $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make help      $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make test      $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make mem      $(RED)|$(NOC)"
	@echo "$(RED)==================$(NOC)"

.PHONY:	all clean fclean re bonus test t1 t2 mem tester norm name build

# this will add the file dependencies below, i.e. it modifies this file
depend:
		makedepend -I${HEAD} -I${LIBDIR} -- ${SRC_DIR}$(SRCS)

# DO NOT DELETE THIS LINE -- make depend depends on it.