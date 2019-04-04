# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/07 18:40:55 by rreedy            #+#    #+#              #
#    Updated: 2019/04/04 16:04:34 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minishell
LIB += libft/libft.a

OBJS := $(patsubst %.c,%.o,$(wildcard ./srcs/*.c))
BUILTINOBJS := $(patsubst %.c,%.o,$(wildcard ./srcs/builtins/*.c))


CC := gcc
INCLUDES := -I./includes -I./libft/includes
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
