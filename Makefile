SRCS =		dispatchflag.c ft_printf.c ft_putchar.c ft_putnbr_base.c ft_putnbr.c ft_putptr.c ft_putstr.c ft_putuns.c strcreate.c validateflag.c

LIB =		libft.a

OBJS =		${SRCS:.c=.o}

CFLAGS =	-Wall -Wextra -Werror

RM =		rm -f

CC =		gcc

NAME =		libprintf.a

AR =		ar rc -s

EX =		ar -xv

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}
.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
all:		${NAME}
clean:
			${RM} ${OBJS}
fclean:		clean
			${RM} ${NAME}
re:			fclean all
.PHONY:		all clean fclean re