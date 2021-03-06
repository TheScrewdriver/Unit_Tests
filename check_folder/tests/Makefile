# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 10:49:20 by romannbroque      #+#    #+#              #
#    Updated: 2022/04/13 17:12:40 by romannbroque     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = exe

########## SRCS

PATH_SRCS += ../srcs/

SRCS += ft_putstr.c
SRCS += check.c

vpath %.c $(PATH_SRCS)

########## OBJS

PATH_OBJS += objs
OBJS = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

########## INCLUDES

INCLUDES += ../includes/
INCLUDES += -I /opt/homebrew/opt/check/include/

HEADER += header.h
HEADER += check.h

LIB += /opt/homebrew/opt/check/lib

vpath %.h $(INCLUDES)

########## COMPILER

CC = clang

CFLAGS += -Wall
CFLAGS += -Werror
CFLAGS += -Wextra

LINKS += -lcheck
LINKS += -lm
LINKS += -lpthread

ifeq ($(debug), true)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address,undefined
endif

########## RULES

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -L $(LIB) $(LINKS) -o $@ -I $(INCLUDES)
	@echo $(NAME) COMPILED !

$(PATH_OBJS):
	mkdir $@

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADER) $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

clean:
	$(RM) -R $(PATH_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE)

.PHONY: all clean fclean re
