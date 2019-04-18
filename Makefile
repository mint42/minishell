# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/07 18:40:55 by rreedy            #+#    #+#              #
#    Updated: 2019/04/17 19:08:40 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minishell
LIB += lib/libft.a

OBJS := $(patsubst %.c,%.o,$(wildcard ./srcs/*.c))
BUILTINOBJS := $(patsubst %.c,%.o,$(wildcard ./srcs/builtins/*.c))


CC := gcc
INCLUDES := -I./includes -I./lib/includes -I./lib/includes/ft_printf
CFLAGS += -Wall -Wextra -Werror $(INCLUDES)
LFLAGS += -L./lib -lft

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIB) $(OBJS) $(BUILTINOBJS)
	$(CC) $(CFLAGS) $(OBJS) $(BUILTINOBJS) -o $(NAME) $(LFLAGS)

$(LIB):
	@- make -C lib/ all

clean:
	@- $(RM) $(OBJS) $(BUILTINOBJS)
	@- make -C lib/ clean

fclean: clean
	@- $(RM) $(NAME)
	@- make -C lib/ fclean

re: fclean all
