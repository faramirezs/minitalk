NAME_SERVER	= server
NAME_CLIENT = client

SRCS_SERVER	= ./libft/ft_printf.c ./libft/ft_numbers.c ./libft/ft_words.c ./libft/ft_atoi.c ./libft/ft_hexa.c server.c
SRCS_CLIENT	= ./libft/ft_printf.c ./libft/ft_numbers.c ./libft/ft_words.c ./libft/ft_atoi.c ./libft/ft_hexa.c client.c

HEADERS	= ./include/minitalk.h

OBJS_SERVER	= $(SRCS_SERVER:.c=.o)
OBJS_CLIENT	= $(SRCS_CLIENT:.c=.o)

CC	= cc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror -I./include

all:	$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):	$(OBJS_SERVER) $(HEADERS)
		$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER)

$(NAME_CLIENT):	$(OBJS_CLIENT) $(HEADERS)
		$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)

fclean:		clean
		$(RM) $(NAME_SERVER) $(NAME_CLIENT)

re:			fclean all

.PHONY:		all clean fclean re
