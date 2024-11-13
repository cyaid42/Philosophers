NAME = philo

SRCS = main.c\
		parsing.c\
		routine.c\
		init.c\
		death.c\
		meal_count.c\
		action.c\
		print.c\
		
IFLAGS = -Iincludes

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -g3 -Wall -Werror -Wextra -pthread

RM = rm -f

all: ${NAME}


${NAME}: $(OBJS)
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}

.c:.o
			${CC} -c $< -o ${<:.c=.o} 


clean:
			${RM} ${OBJS}

fclean: clean
			${RM} ${NAME}

re: fclean all


.PHONY:  all clean fclean re