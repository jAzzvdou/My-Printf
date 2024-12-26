NAME	=	libftprintf.a

SRCS	=	my_printf.c       \
		flags.c           \
		percent_printer.c \
		c_printer.c       \
		s_printer.c       \
		iduxx_printer.c   \
		help_iduxx.c	  \
		ptr_printer.c	  \
		help_functions.c  \


OBJS	=	$(SRCS:.c=.o)

CC	=	cc

CFLAGS	=	-Wall -Wextra -Werror

RM	=	rm -rf

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

bonus: $(NAME)

.c.o:
		$(CC) $(CFLAGS) -c $<

clean:
		$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
