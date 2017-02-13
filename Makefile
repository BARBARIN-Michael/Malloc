# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/07 16:55:33 by mbarbari          #+#    #+#              #
#    Updated: 2017/02/13 11:36:41 by barbare          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC ?= gcc
CX ?= clang++

malloc:
	make -C ./malloc/

test:
	make -C ./test/ alltest

re:
	make -C ./Libs/libft/libft/ re
	make -C ./malloc/ re

clean:
	make -C ./client/ clean
	make -C ./malloc/ clean

fclean: clean
	make -C ./malloc/ fclean
	make -C ./Libs/libft/libft/ fclean

re: fclean all

.PHONY: clean fclean re all
