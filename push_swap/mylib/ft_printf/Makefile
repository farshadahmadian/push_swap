# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 13:37:41 by fahmadia          #+#    #+#              #
#    Updated: 2023/06/08 15:16:14 by fahmadia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = count_num_of_digits.c\
	find_format_spec.c\
	to_power.c\
	ft_printf.c\
	print_c.c\
	print_i.c\
	print_p.c\
	print_percent.c\
	print_s.c\
	print_x.c\
	putnbr_long_int.c\
	print_without_format_spec.c\

OBJS = $(SRCS:%.c=%.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = ./libftprintf.a
LIBFT_DIR = ../libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
HEADER = ./ft_printf.h

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB) # rule $(NAME) has variable $(OBJS) as dependency. If $(OBJS) does not exist or if $(OBJS) is older that variable $(NAME) (means if REAL .o files do not exist or if they are older that REAL .c files) (the value of SRCS, OBJS, NAME are all string but these strings are address of .c .o or .a files), $(OBJS) rule will execute. $(OBJS) rule is actually %.o: because %.o are object files and %.c are source files. In "$(CC) -c $(CFLAGS) $< -o $@" $< is %.c which is a source file and $@ is %.o which is an object file. so $< refers to SRCS and $@ refers to OBJS
	cp $(LIBFT_LIB) $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) -g -c $(CFLAGS) $< -o $@ 

$(LIBFT_LIB): 
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)
fclean:	clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
# re: fclean $(NAME)
re: 
	make fclean
	make $(NAME)

.PHONY: all clean fclean re

# when we write "make" in command line:
# "make all" is executed, it has $(NAME) as dependency. if $(NAME) does not exis or if $(NAME) is older than all (which has no meaning here), $(NAME) will be executed. Also, in one other case $(NAME) rule will be executed: Because $(NAME) has $(OBJS) as dependency, if $(OBJS) does not exist or is older than $(NAME), $(NAME) rule will be executed EVEN IF $(NAME) EXSISTS. Also, if $(OBJS) do not exist or is older than $(NAME), before $(NAME) rule gets executed, $(OBJS) RULE must be executed, but we have NO $(OBJS) rule! $(OBJS) refer to all REAL object files the same thing that %.o does so %.o: will be executed instead of $(OBJS) rule. %.o has %.c as dependency, so %.o rule will be executed if %.c (the relevant .c file) does not exist or is older than %.o, which will create the object file for its counterpart source file. $(NAME) has also ../libft/libft.a as dependency, because if the ../libft/libft.a library changes, our ./libftprintf.a must be created again because it will change as well. So, if $(LIBT_LIB) does not exist or is older than $(NAME), $(LIBFT_LIB) rule will be executed. Then we copy ../libft/libft.a to ./ and rename to to libftprintf.a. In the next line we add the $(OBJS) which are object files of ft_printf project to the LIBRARY archive libftprintf.a