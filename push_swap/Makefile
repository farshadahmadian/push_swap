# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 17:34:04 by fahmadia          #+#    #+#              #
#    Updated: 2023/06/28 15:28:54 by fahmadia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH = srcs
SRCS = main.c\
	validate_args.c\
	check_argv_or_split.c\
	check_for_minus_or_plus.c\
	free_double_pointer.c\
	convert_to_long.c\
	check_for_int_range.c\
	add_node_at_end.c\
	create_node.c\
	get_length_of_list.c\
	check_for_duplication.c\
	free_list.c\
	delete_node_content.c\
	check_for_digits.c\
	throw_an_error.c\
	rotate.c\
	reverse_rotate.c\
	swap.c\
	push.c\
	sort_three_or_less_numbers.c\
	sort_four_or_five_numbers.c\
	get_tail_of_list.c\
	math.c\
	sort_six_or_more_numbers.c\
	get_pointer_to_a_node.c\
	push_the_best_num.c\
	choose_rotate_or_rev_rotate.c\
	check_if_already_sorted.c\
	compare_with_min_and_max.c\
	simulate_movement.c\
	find_best_node.c\
	handle_rr_or_rrr.c\
	handle_no_rr_or_rrr.c\
	handle_rr_or_rrr_set.c\
	find_target_node_in_other_stack.c\
	handle_equal_upward_and_downward_distances.c\

OBJS_DIR = ./objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.c=%.o))
MYLIB_DIR = ./mylib
MYLIB_LIB = $(MYLIB_DIR)/mylib.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
HEADER = ./push_swap.h
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS) $(MYLIB_LIB) Makefile
	$(CC) $(OBJS) $(MYLIB_LIB) -o ${NAME}

$(OBJS_DIR)/%.o: %.c $(HEADER) Makefile
	mkdir -p $(OBJS_DIR)
	$(CC) -g -c $(CFLAGS) $< -o $@

$(MYLIB_LIB):
	make -C $(MYLIB_DIR)

clean:
	make clean -C $(MYLIB_DIR)

fclean: clean
	rm -f $(OBJS)
	rm -rf $(OBJS_DIR)
	make fclean -C $(MYLIB_DIR)
	rm -f push_swap
	rm -rf push_swap.dSYM

re: fclean $(NAME)

.PHONY: all clean fclean re bonus
