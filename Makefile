# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 17:34:04 by fahmadia          #+#    #+#              #
#    Updated: 2023/06/10 16:11:18 by fahmadia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH = srcs
SRCS = push_swap.c\
	main.c\
	validate_args.c\
	check_for_space.c\
	check_for_digits.c\
	check_for_minus_or_plus.c

OBJS_DIR = ./objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.c=%.o)) 
MYLIB_DIR = ./mylib
MYLIB_LIB = $(MYLIB_DIR)/mylib.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
HEADER = ./push_swap.h
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS) $(MYLIB_LIB) 
	$(CC) $(OBJS) $(MYLIB_LIB) -o ${NAME}

$(OBJS_DIR)/%.o: %.c $(HEADER)
	mkdir -p $(OBJS_DIR)
	$(CC) -g -c $(CFLAGS) $< -o $@

$(MYLIB_LIB):
	make -C $(MYLIB_DIR)

clean:
	rm -f $(OBJS)
	rm -rf $(OBJS_DIR)
	make clean -C $(MYLIB_DIR)

fclean: clean
	make fclean -C $(MYLIB_DIR)
	rm -f push_swap

re: fclean $(NAME)

.PHONY: all clean fclean re bonus
