SRCS =			dispatchflag.c ft_printf.c ft_putchar.c ft_putnbr_base.c ft_putnbr.c ft_putptr.c ft_putstr.c ft_putuns.c strcreate.c validateflag.c

SRCS_LIBFT =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
				ft_itoa.c ft_lstadd_back.c ft_lastadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
				ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
				ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
				ft_strdup.c ft_strteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
				ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_subtr.c ft_tolower.c ft_toupper.c

NAME =			libprintf.a

OBJS +=			${SRCS:.c=.o}
OBJS +=			${addprefix ${LIBFT_PATH},${SRCS_LIBFT:.c=.o}}

LIBFT_PATH =	/libft

CFLAGS =		-Wall -Wextra -Werror

RM =			rm -f

CC =			gcc

AR =			ar rc -s

${NAME}:		${OBJS}
				${AR} ${NAME} ${OBJS}
.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
all:			${NAME}
clean:
				${RM} ${OBJS}
fclean:			clean
				${RM} ${NAME}
re:				fclean all
.PHONY:			all clean fclean re