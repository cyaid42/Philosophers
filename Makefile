NAME = pipex

SRCS = main.c\
	   parsing.c\
	   philo.c\


OBJS = ${SRCS:.c=.o}

CC = cc

CCFLAGS = -g

RM = rm -f

all: ${NAME}

$(NAME): $(OBJS)
	$(MAKE) -C ./Libft
	${CC}  $(CCFLAGS) $(SRCS) -o $(NAME)

.c.o:
			${CC} -c $< -o ${<:.c=.o} 


clean:
			${RM} ${OBJS} 
			$(MAKE) clean -C ./Libft

fclean: clean
			${RM} ${NAME}
			$(MAKE) fclean -C ./Libft

re: fclean all


.PHONY:  all clean fclean re