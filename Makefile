# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/07 16:55:33 by mbarbari          #+#    #+#              #
#    Updated: 2017/03/24 12:01:03 by mbarbari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC ?= gcc
CX ?= clang++

malloc:
	make -C ./malloc/

re:
	make -C ./libs/libft/ re
	make -C ./malloc/ re

clean:
	make -C ./libs/libft/ clean
	make -C ./malloc/ clean

fclean: clean
	make -C ./malloc/ fclean
	make -C ./Libs/libft/ fclean

re: fclean all

.PHONY: clean fclean re all
