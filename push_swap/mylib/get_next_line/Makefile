# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 15:31:49 by fahmadia          #+#    #+#              #
#    Updated: 2023/06/08 15:16:30 by fahmadia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = get_next_line_utils.c\
	get_next_line.c\

BONUS = get_next_line_bonus.c\
	get_next_line_utils_bonus.c\
	

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = getnextline.a
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)
HEADER = ./get_next_line.h

all: $(NAME)

$(NAME): $(OBJS) #the $(NAME) rule executes only if $(OBJS) does not exist or is older that $(NAME). Also, $(OBJS) rule (or actually %.o: rule) executes before that, if $(OBJS) (%.o) is older than SRCS (%.c). Actually, in 2 other cases rule $(NAME) will be executed and that is when $(HEADER) or $(SRCS) (or %.c) does not exist or one of them is older than $(OBJS) (or %.o) WHY? Becase $(NAME) dependse on $(OBJS) and $(OBJS) (or %.o) dependds on SRCS (%.c) and $(HEADER) so when rule $(NAME) wants to be executed, it checks if 1) $(OBJS) (%.o) exists? If yes, it checks if 2) $(OBJS) (%.o) is older than $(NAME) if yes, it chcks if 3) $(OBJS) rule (%.o) needs to be run or not (if $(OBJS) (or %.o) dependencies are newer or older than $(OBJS) (or %.o)) if SRCS (or %.c) and $(HEADER) exist and are older than $(OBJS) (or %.o), then rule $(OBJS) (or %.o) does not need to be exeuted and rule $(NAME) does not need to be executed either. BUT, let's asume that $(HEADER) is newer than $(OBJS) or $(%.o) so when we type "make" in command line, it goes to all rule and then $(NAME) rule. Now, although $(OBJS) is older than $(NAME), but it ALSO checks for the dependencies of $(OBJS) rues (or .o) the same as it checked for the dpendencies of $(NAME). Now, it sees that $(HEADER) is newer than $(OBJS) or (%.o) so it first runs the $(OBJS) rule (or %.o rule) and now we have $(OBJS) (or %.o) which is newer than $(NAME) so now the rule $(NAME) must be executed
#  BUT the rule bonus: ALWAYS executes because the target of the rule (bonus) is not something that exists so that we can compare $(OBJS) and $(BOUNS_OBJS) with. IF $(OBJS) or $(BONUS_OBJS) does not exist or if they (the .o files) are older than SRCS or BONUS (.c files) the %.o: rule will be execute instead of $(OBJS) or $(BONUS_OBJS) rules, if they exist and are newer than .c files, then only "ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)" will be executed
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) -g -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) 

re: fclean $(NAME)

bonus: $(OBJS) $(BONUS_OBJS) # if we omit $(OBJS) in this line and the next line, we can compile only the bonus objects (look at the next comment)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus

# When we execute make command in terminal, it executes the rule all, which executes the rule $(NAME) if $(NAME) variable does not exist or if it is older than all which does not mean anything here. Also the rule $(NAME) will be executed if $(OBJS) or $(HEADER) do not exist or are older that $(NAME) variable, but first $(OBJS) or $(HEADER) will be executed and then $(NAME) rule will be executed.

# When $(NAME) rule wants to be executed, first $(OBJS) and $(HEADER) are checked. If they exist and newer than $(NAME), $(NAME) rule does not get executed. Lets assume, $(OBJS) do not exist. So, the $(OBJS) rule must be executed so that $(OBJS) is created and after taht $(NAME) can be executed using $(OBJS) but no rule called $(OBJS) exist, why? %.o means similar, so instead of $(OBJS) rule, %.o rule gets executed. What does it do? It checks for .c (SRCS) files which are counter parts to $(OBJS) (SRCS = get_next_line_utils.c	get_next_line.c) (NOT BONUS FILES, ONLY SRCS) if they are older than .o counterpart or if .o does not exist, "$(CC) -c $(CFLAGS) $< -o $@" gets execute for each .o file and .c file of SRCS, NOT BONUS. The same thing happens for bonus rule. bonus: $(OBJS) $(BONUS_OBJS) bonus rules has two dependencies $(OBJS) and (BONUS_OBJS) so %.o rules gets executed for both SRCS and BONUS files