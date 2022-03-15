SRCS =			dispatchflag.c ft_printf.c printchar.c ft_putnbr_base.c ft_putnbr.c ft_putptr.c ft_putstr.c \
				ft_putuns.c strcreate.c validateflag.c ft_putptr_base.c

SRCSA =			dispatchflag.c ft_printf.c printchar.c ft_putnbr_base.c ft_putnbr.c ft_putptr.c ft_putstr.c \
				ft_putuns.c strcreate.c validateflag.c ft_putptr_base.c main.c

SRCS_LIBFT =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
				ft_itoa.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
				ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
				ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
				ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
				ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

SRCS_BONUS =	dotfield_bonus.c findfieldwidth_bonus.c findformat_bonus.c flagnum_bonus.c ft_itoa_base_bonus.c \
				ft_printf_bonus.c ft_putchar_bonus.c ft_putnbr_base.c ft_putnbr_bonus.c ft_putstr_bonus.c \
				ft_putuns_bonus.c initstruct_bonus.c memalloc_bonus.c memsizebase_bonus.c numsize_bonus.c numsizedot_bonus.c \
				parseformat_bonus.c popstructone_bonus.c popstructtwo_bonus.c printall_bonus.c printchar.c \
				printformat_bonus.c printhex_bonus.c printhexminus_bonus.c printhexminusopt_bonus.c printhexreg_bonus.c \
				printhexsharp_bonus.c printnumberone_bonus.c printnumbertwo_bonus.c printnumberthree_bonus.c \
				printnumminus_bonus.c printnumminustwo_bonus.c printnumzero_bonus.c printox_bonus.c printpercent_bonus.c \
				printpointer_bonus.c printunsigned_bonus.c stringlen_bonus.c subflag_bonus.c validateflag.c ft_putstrnull_bonus.c \
				printunsignedtwo_bonus.c ft_putnbr_base_bonus.c ft_putstrtwo_bonus.c memsizebaseuns_bonus.c printnumminusthree_bonus.c \
				printunsminus_bonus.c printnumsign_bonus.c printnumspace_bonus.c printunsdot_bonus.c printhexregdot_bonus.c \
				printhexsharptwo_bonus.c

SRCS_BONUSA =	dotfield_bonus.c findfieldwidth_bonus.c findformat_bonus.c flagnum_bonus.c ft_itoa_base_bonus.c \
				ft_printf_bonus.c ft_putchar_bonus.c ft_putnbr_base.c ft_putnbr_bonus.c ft_putstr_bonus.c \
				ft_putuns_bonus.c initstruct_bonus.c memalloc_bonus.c memsizebase_bonus.c numsize_bonus.c numsizedot_bonus.c \
				parseformat_bonus.c popstructone_bonus.c popstructtwo_bonus.c printall_bonus.c printchar.c \
				printformat_bonus.c printhex_bonus.c printhexminus_bonus.c printhexminusopt_bonus.c printhexreg_bonus.c \
				printhexsharp_bonus.c printnumberone_bonus.c printnumbertwo_bonus.c printnumberthree_bonus.c \
				printnumminus_bonus.c printnumminustwo_bonus.c printnumzero_bonus.c printox_bonus.c printpercent_bonus.c \
				printpointer_bonus.c printunsigned_bonus.c stringlen_bonus.c subflag_bonus.c validateflag.c ft_putstrnull_bonus.c \
				printunsignedtwo_bonus.c ft_putnbr_base_bonus.c ft_putstrtwo_bonus.c memsizebaseuns_bonus.c printnumminusthree_bonus.c \
				printunsminus_bonus.c printnumsign_bonus.c printnumspace_bonus.c printunsdot_bonus.c printhexregdot_bonus.c \
				printhexsharptwo_bonus.c main.c

NAME =			libftprintf.a

NAMEA =			a.out

OBJS +=			${SRCS:.c=.o}
OBJS +=			${addprefix ${LIBFT_PATH},${SRCS_LIBFT:.c=.o}}

OBJSA +=		${SRCS:.c=.o}
OBJSA +=		${addprefix ${LIBFT_PATH},${SRCS_LIBFT:.c=.o}}

OBJSBONUS += 	${SRCS_BONUS:.c=.o}
OBJSBONUS += 	${addprefix ${LIBFT_PATH}, ${SRCS_LIBFT:.c=.o}}

OBJSBONUSA += 	${SRCS_BONUS:.c=.o}
OBJSBONUSA += 	${addprefix ${LIBFT_PATH}, ${SRCS_LIBFT:.c=.o}}

LIBFT_PATH =	libft/

CFLAGS =		-Wall -Wextra -Werror

RM =			rm -f

CC =			gcc

AR =			ar rc -s

${NAME}:		${OBJS}
				${AR} ${NAME} ${OBJS}
.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
bonus:			${OBJSBONUS}
				${AR} ${NAME} ${OBJSBONUS}
man: 			${OBJSA}
				${CC} ${CFLAGS} ${OBJSA}
bonusrun:		${OBJSBONUSA}
				${CC} ${CFLAGS} ${OBJSBONUSA}
all:			${NAME}
clean:
				${RM} ${OBJS} ${OBJSBONUS} ${OBJSA} ${OBJSBONUSA}
fclean:			clean
				${RM} ${NAME} ${NAMEA}
re:				fclean all
.PHONY:			all clean fclean re bonus man bonusrun