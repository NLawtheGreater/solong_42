# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niclaw <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 13:59:17 by niclaw            #+#    #+#              #
#    Updated: 2022/10/28 21:23:52 by niclaw           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCLIST	=   printf_format.c ft_printf.c  printf_conversion_x.c printf_conversion_u.c \
			printf_conversion_type.c printf_conversion_s.c printf_conversion_p.c \
			printf_conversion_d.c printf_conversion_c.c 
SRCDIR	= 
BUILD =	./build/
OBJS	=	${SRCS:%.c=%.o}
BONUS_OBJS = ${BONUS_SRC:.c=.o}
INCH	= ft_printf.h 
INCHB	= 
LIBFT	= ${LIBDIR}/libft.a
LIBDIR	= ./libft
LIB_SRC= ${addprefix ${LIBDIR}, ${LIBFT}}
BONUS_SRC	=  
SRCS	= ${addprefix ${SRCDIR}, ${SRCLIST}}
LIB_OBJS = ${LIB_SRC: .c=.o}

CC	= gcc

CFLAGS	= -g -Wall -Wextra -Werror

RM	= rm -f

NAME	= libftprintf.a

%.o:	%.c ${INCH} ${LIBDIR}
	@mkdir -p ${BUILD}
	${CC} ${CFLAGS} -include ${INCH} -I ${LIBDIR}\
	 -c $< -o ${addprefix ${BUILD}, ${<:.c=.o}}

%bonus.o:	%bonus.c ${INCHB}
	${CC} ${CFLAGS} -include ${INCHB} -c $< -o ${<:.c=.o}

${LIBFT}:
	make -C ${LIBDIR}
	cp ${LIBFT} ${NAME}

${NAME}:	${OBJS} ${LIBFT}
	ar -crs ${NAME} ${addprefix ${BUILD}, ${OBJS}}
	@echo "Linking Done!" 

all:	${NAME}

clean:
	${RM} -r ${BUILD}
	make clean -C ${LIBDIR} 

fclean:	clean
	${RM} ${NAME}
	make fclean -C ${LIBDIR} 

re:	fclean all

.PHONY:	all clean fclean re  

bonus: all

test:	
	${CC} -g -Wall -Wextra -include ${INCH} -I ${LIBDIR} playground.c ${NAME} -o playground
	./playground

mem: 
	${CC} -g -Wall -Wextra -include ${INCH} -I ${LIBDIR} playground.c ${NAME} -o playground
	./playground
	valgrind -v --leak-check=full ./playground
