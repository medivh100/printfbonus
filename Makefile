SRCS =          src/dispatchflag.c src/ft_printf.c src/printchar.c src/ft_putnbr_base.c src/ft_putnbr.c src/ft_putptr.c src/ft_putstr.c \
				src/ft_putuns.c src/strcreate.c src/validateflag.c src/ft_putptr_base.c

SRCS_BONUS =    src/dotfield_bonus.c src/findfieldwidth_bonus.c src/findformat_bonus.c src/flagnum_bonus.c src/ft_itoa_base_bonus.c \
				src/ft_printf_bonus.c src/ft_putchar_bonus.c src/ft_putnbr_base.c src/ft_putnbr_bonus.c src/ft_putstr_bonus.c \
				src/ft_putuns_bonus.c src/initstruct_bonus.c src/memalloc_bonus.c src/memsizebase_bonus.c src/numsize_bonus.c src/numsizedot_bonus.c \
				src/parseformat_bonus.c src/popstructone_bonus.c src/popstructtwo_bonus.c src/printall_bonus.c src/printchar.c \
				src/printformat_bonus.c src/printhex_bonus.c src/printhexminus_bonus.c src/printhexminusopt_bonus.c src/printhexreg_bonus.c \
				src/printhexsharp_bonus.c src/printnumberone_bonus.c src/printnumbertwo_bonus.c src/printnumberthree_bonus.c \
				src/printnumminus_bonus.c src/printnumminustwo_bonus.c src/printnumzero_bonus.c src/printox_bonus.c src/printpercent_bonus.c \
				src/printpointer_bonus.c src/printunsigned_bonus.c src/stringlen_bonus.c src/subflag_bonus.c src/validateflag.c src/ft_putstrnull_bonus.c \
				src/printunsignedtwo_bonus.c src/ft_putnbr_base_bonus.c src/ft_putstrtwo_bonus.c src/memsizebaseuns_bonus.c src/printnumminusthree_bonus.c \
				src/printunsminus_bonus.c src/printnumsign_bonus.c src/printnumspace_bonus.c src/printunsdot_bonus.c src/printhexregdot_bonus.c \
				src/printhexsharptwo_bonus.c

MAIN =          main.c

NAMEA =         a.out

NAME =          libftprintf.a

RULE =          bonus

OBJS =          ${SRCS:.c=.o}

OBJSBONUS =     ${SRCS_BONUS:.c=.o}

MAINOBJ =       ${MAIN:.c=.o}

SRC_PATH =		src/

LIBFT_PATH =    libft/

LIBFT =         libft.a

CFLAGS =        -Wall -Wextra -Werror -g

RM =            rm -f

CC =            gcc

AR =            ar rsc

all:			${NAME}

bonus:			${OBJSBONUS}
				make -C ${LIBFT_PATH} ${RULE}
				cp ${LIBFT_PATH}${LIBFT} ./${NAME}
				${AR} ${NAME} ${OBJSBONUS}

${NAME}:		${OBJS}
				make -C ${LIBFT_PATH} ${RULE}
				cp ${LIBFT_PATH}${LIBFT} ./${NAME}
				${AR} ${NAME} ${OBJS}

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

mrun:			${NAME} ${OBJS} ${MAINOBJ}
				${CC} ${CFLAGS} ${OBJS} ${MAINOBJ} ${NAME}

brun:			bonus ${OBJSBONUS} ${MAINOBJ}
				${CC} ${CFLAGS} ${OBJSBONUS} ${MAINOBJ} ${NAME}

clean:
				${RM} ${OBJS} ${OBJSBONUS} ${MAINOBJ} ${OBJSA} ${OBJSBONUSA} && make -C ${LIBFT_PATH} fclean

fclean:			clean
				${RM} ${NAME} ${NAMEA}

re:				fclean all

.PHONY:			all clean fclean re bonus mrun brun