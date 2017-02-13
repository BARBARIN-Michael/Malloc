# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/07 16:55:33 by mbarbari          #+#    #+#              #
#    Updated: 2017/02/13 11:14:49 by barbare          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC ?= gcc
CX ?= clang++
CFLAGS += -g -Wall -Wextra -Werror

SRC_INCLUDE = ./../malloc/inc/*.h

RM ?= rm -f
MKDIR ?= mkdir

all:
	@echo "Please send file test (EX: make test1)"

%:
	@$(CC) -c $(CFLAGS) $(INC) $@.c -o $@.o
	@$(CC) $(CFLAGS) -o $@ $@.o $(INC) $(LIBS)
	@$(RM) $@.o
	@LD_PRELOAD=../malloc/libft_malloc_x86_64_Linux.so ./$@
	@$(RM) $@

obj/%.o: src/%.c $(SRC_INCLUDE)
	$(MKDIR) -p $(dir $@)
	$(CC) -c $(CFLAGS) $(INC) $< -o $@

../common/obj/%.o: ../common/src/%.c $(SRC_INCLUDE)
	$(MKDIR) -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@ -I../common/include -I../common/libft/libft/include

clean:
	$(RM) $(CLI_OBJS)
	$(RM) $(COM_OBJS)

fclean: clean
	$(RM) cli

re: fclean all

.PHONY: clean fclean re all
