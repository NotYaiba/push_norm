SRCS = push_swap.c\
		comds.c\
		helpers.c\
		helpers2.c\
		get_next_line.c\
		get_next_line_utils.c\
		list_utils.c\
		ft_split.c\
		push_fiveh.c\
		helpers3.c\
		list_utils3.c\
		list_utils2.c\
		sort_four.c\
		sort_three.c\
		sort_oneh.c\
		sort_oneh_utils.c\
		comds2.c\
		comds3.c\
		init_struct.c\

SRCSB = checker.c\
		comds.c\
		comds2.c\
		comds3.c\
		helpers.c\
		helpers2.c\
		get_next_line.c\
		get_next_line_utils.c\
		list_utils.c\
		ft_split.c\
		push_fiveh.c\
		helpers3.c\
		list_utils3.c\
		list_utils2.c\
		init_struct.c\

		
INCL = -INCLUDES/

OBJS = ${SRCS:.c=.o}
OBJSB = ${SRCSB:.c=.o}

NAME = push_swap
NAMEB = checker
FLAGS = -Wall -Wextra -Werror #-g -fsanitize=address


all : $(NAME)


$(NAME) : ${OBJS}
		@gcc  ${OBJS} -g -o$(NAME)
		@rm -f ${OBJS} 
bonus : ${OBJSB}
		@gcc  ${OBJSB} -g -o$(NAMEB) -g 
		@rm -f ${OBJSB} 
# .c.o : ${SRCS}
# 		@gcc  -c ${INCL} $< -o ${<:.c=.o}
clean :
		@rm -f ${OBJS}
fclean : clean
		@rm -f $(NAME)
re : fclean
		make all

		# gcc checker.c list_utils.c comds.c get_next_line.c get_next_line_utils.c helpers.c helpers2.c
