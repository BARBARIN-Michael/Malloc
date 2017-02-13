# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/07 16:55:33 by mbarbari          #+#    #+#              #
#    Updated: 2017/02/13 11:56:34 by barbare          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so

CC = clang
CX = clang++
CFLAGS += -g -Wall -Wextra -Werror

LIBFTDIR = ../Libs/libft/
LIBFT = libft.a

INC = -I./inc  -I../Libs/libft/include
LIBS = -L$(LIBFTDIR) -lft

SRCS = 	src/malloc.c 		\
		src/tiny_malloc.c 	\
		src/memory.c		\
		src/block.c			\

OBJS = $(patsubst src/%.c,obj/%.o,$(SRCS))

SRC_INCLUDE = ./inc/*.h

RM ?= rm -f
MKDIR ?= mkdir

all: $(NAME)

print-% : ; $(info $* is $(flavor $*) variable set to [$($*)]) @true

$(NAME): $(LIBFTDIR)$(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -shared -o $@ $^ $(INC) $(LIBS)

obj/%.o: src/%.c $(SRC_INCLUDE)
	$(MKDIR) -p $(dir $@)
	$(CC) -c -fpic $(CFLAGS) $(INC) $< -o $@

$(LIBFTDIR)$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(OBJS)

re: clean all

.PHONY: clean fclean re all
