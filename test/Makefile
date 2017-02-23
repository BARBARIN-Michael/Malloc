# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/07 16:55:33 by mbarbari          #+#    #+#              #
#    Updated: 2017/02/14 12:41:53 by barbare          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC ?= clang
CX ?= clang++
CFLAGS += -g -Wall -Wextra -Werror
INCLIBS = /home/barbare/42/malloc/malloc/inc
DIRLIBS = /home/barbare/42/malloc/malloc/

RM ?= rm -f
MKDIR ?= mkdir

all:
	@echo "Please send file test (EX: make test1)"

%:
	$(CC) $(CFLAGS) -I$(INCLIBS) -L$(DIRLIBS) -o test $@.c -lft_malloc_x86_64_Linux
	./test
	@$(RM) *.o

clean:
	$(RM) $(CLI_OBJS)
	$(RM) $(COM_OBJS)

fclean: clean
	$(RM) cli

re: fclean all

.PHONY: clean fclean re all
