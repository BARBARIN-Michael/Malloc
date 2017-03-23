# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/07 16:55:33 by mbarbari          #+#    #+#              #
#    Updated: 2017/03/23 17:30:11 by barbare          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
HOSTTYPE :=  $(shell uname -m)_$(shell uname -s)
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
		src/print_malloc.c 	\
		src/memory.c		\
		src/ft_malloc_rec.c	\
		src/block.c			\
		src/realloc.c			\
		src/free.c

OBJS = $(patsubst src/%.c,obj/%.o,$(SRCS))

SRC_INCLUDE = ./inc/*.h

RM ?= rm -f
MKDIR ?= mkdir
DIR = $(shell pwd)

all: $(NAME)

print-% : ; $(info $* is $(flavor $*) variable set to [$($*)]) @true

$(NAME): $(LIBFTDIR)$(LIBFT) $(OBJS)
	$(shell export LIBRARY_PATH=$(DIR))
	$(CC) $(CFLAGS) -Wl,--version-script=malloc.export -shared -o $@ $^ $(INC) $(LIBS)

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
