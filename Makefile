# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 17:34:04 by fahmadia          #+#    #+#              #
#    Updated: 2023/06/10 11:12:43 by fahmadia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH = srcs
SRCS = push_swap.c\
	main.c\
	validate_args.c\
	check_for_space.c\
	check_for_digits.c\

OBJS_DIR = ./objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.c=%.o)) # This line 1) does NOT create REAL object files (.o), and 2) does NOT create a file named something.o either. This line JUST 3) creates a variable whose value is a STRING which is exactly like the value of the variable SRCS (another string), except all the .c will replace by .o Wy do we need such variable at all? When we run for example "cc -c push_swap.c -o push_swap.o" the push_swap.o object file is created. Now we want this push_swap.o object file to be a dependancy of $(NAME) rule which means if the push_swap.o object file does not exist or if it is older than $(NAME) which is the library, then run "cc -c push_swap.c -o push_swap.o" again. when we set $(OBJS) as the dependency of $(NAME) rule, we are actually setting ALL REAL OBJECT FILES as the dependency of $(NAME) rule
MYLIB_DIR = ./mylib
MYLIB_LIB = $(MYLIB_DIR)/mylib.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
HEADER = ./push_swap.h
NAME = push_swap

all: $(NAME)

# $(OBJS) is a dependecy for $(NAME) rule, so if $(OBJS) does not exist, first creat $(OBJS) HOW? Just in all the $(SRCS) file names, instead of .c, put .o If I delete the $(OBJS) every time I run make, then the next time I run make, $(OBJS) does not exist, so even if $(NAME) exists, $(NAME) command will run again because "all" rule has $(NAME) as dependency and $(NAME) rule has $(OBJS) as dependancy. So, if $(OBJS) does not exist, $(NAME) will execute. So I need to keep object files, and do need delete them in every make. even if I move the $(OBJS) again the next time make runs, it does not find $(OBJS) so runs the $(NAME) rule again.
# Now the problem is that I want my $(OBJS) be in another folder like ./o_files. So, If I can create $(OBJS) in that folder from the beginning (insted of "OBJS = $(SRCS:.c=.o)" create $(OBJS) directly in ./o_files folder) and also when running cc, put REAL .o files in that folder, the problem will be solved 
# The line below creats REAL object files out of source files (creats an object file for each source file) and gives the object files the exact name of the source file just with .o extention instead of .c
$(NAME): $(OBJS) $(MYLIB_LIB) 
#if $(MYLIB_LIB) does not exist, when it reaches to line below, will throw an error so we need to add $(MYLIB_LIB) to dependencies, so that it executes $(MYLIB_LIB) rule to create $(MYLIB_LIB)
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
