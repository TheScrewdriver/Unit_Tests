# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 10:49:20 by romannbroque      #+#    #+#              #
#    Updated: 2022/04/13 17:27:34 by romannbroque     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = add

########## SRCS

PATH_SRCS += srcs/
PATH_SRCS += tests/

SRCS += ft_putstr.c
SRCS += main.c

vpath %.c $(PATH_SRCS)

########## OBJS

PATH_OBJS += objs
OBJS = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

########## INCLUDES

INCLUDES += includes/

CHECK_FOLDER += tests/

HEADER += header.h

vpath %.h $(INCLUDES)

########## COMPILER

CC = clang

CFLAGS += -Wall
CFLAGS += -Werror
CFLAGS += -Wextra

ifeq ($(debug), true)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address,undefined
endif

########## RULES

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -I $(INCLUDES)
	@echo $(NAME) COMPILED !
	$(MAKE) -C $(CHECK_FOLDER)

$(PATH_OBJS):
	mkdir $@

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADER) $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

clean:
	$(RM) -R $(PATH_OBJS)
	$(MAKE) -C $(CHECK_FOLDER) $@

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(CHECK_FOLDER) $@

re: fclean
	$(MAKE)

.PHONY: all clean fclean re
