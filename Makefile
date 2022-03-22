SRCS =          dispatchflag.c ft_printf.c printchar.c ft_putnbr_base.c ft_putnbr.c ft_putptr.c ft_putstr.c \
				ft_putuns.c strcreate.c validateflag.c ft_putptr_base.c

SRCS_BONUS =    dotfield_bonus.c findfieldwidth_bonus.c findformat_bonus.c flagnum_bonus.c ft_itoa_base_bonus.c \
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

MAIN =          main.c

NAMEA =         a.out

NAME =          libftprintf.a

RULE =          bonus

OBJS =          ${SRCS:.c=.o}

OBJSBONUS =     ${SRCS_BONUS:.c=.o}

MAINOBJ =       ${MAIN:.c=.o}

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