# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/07 18:40:55 by rreedy            #+#    #+#              #
#    Updated: 2019/09/04 17:12:48 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minishell
LIB += libft/libft.a

OBJS := $(patsubst %.c,%.o,$(wildcard ./srcs/*.c))
BUILTINOBJS := $(patsubst %.c,%.o,$(wildcard ./srcs/builtins/*.c))


CC := gcc
INCLUDES := -I./includes -I./libft/includes -I./libft/includes/ft_printf
CFLAGS += -Wall -Wextra -Werror $(INCLUDES)
LFLAGS += -L./libft -lft

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIB) $(OBJS) $(BUILTINOBJS)
	$(CC) $(CFLAGS) $(OBJS) $(BUILTINOBJS) -o $(NAME) $(LFLAGS)

$(LIB):
	@- make -C libft/ all

clean:
	@- $(RM) $(OBJS) $(BUILTINOBJS)
	@- make -C libft/ clean

fclean: clean
	@- $(RM) $(NAME)
	@- make -C libft/ fclean

re: fclean all

install: $(NAME)
	ln -sv $(shell pwd)/$(NAME) ~/bin/squish
