NAME	=	libftprintf.a

SRCS	=	ft_printf.c ft_putchar.c ft_puts.c ft_putstr.c ft_itoa.c ft_strdup.c ft_strlen.c ft_utoa.c ft_utoh.c ft_ultoh.c

HEADER	=	ft_printf.h
OBJS	=	$(patsubst %.c,%.o,$(SRCS))

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(HEADER)
	@ar rcs $(NAME) $?

%.o 	: 	%.c	$(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean	:	
	@rm -f $(OBJS)

fclean	:	clean
	@rm -f $(NAME)

re		:	fclean all