/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 08:59:51 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/29 18:33:08 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./mylib/ft_printf/ft_printf.h"
# include "./mylib/libft/libft.h"

typedef enum t_stack
{
	A = 0,
	B = 1,
	BOTH = 2,
	NO_STACK = 3,
}	t_stack;

typedef enum t_movement
{
	ROTATE,
	REV_ROTATE,
}	t_movement;

typedef struct t_num
{
	int			num;
	int			i;
	int			dist_to_top;
	int			dist_to_bottom;
	int			is_both_dist_same;
	int			best_dist;
	int			tar_best_dist;
	int			tar_move_type;
	int			total_move;
	t_movement	move_type;
	int			has_rr_or_rrr;
	int			num_of_rr_or_rrr;
	int			has_alone_move;
	int			num_of_alone_moves;
}	t_num;

typedef struct t_node
{
	int				content;
	struct t_node	*next;
	t_num			details;
	struct t_node	*target_node;
}	t_node;

typedef struct t_lists
{
	t_node	*a;
	t_node	*b;
}	t_lists;

t_node	*validate_args(int argc, char **argv);
t_node	*check_argv(char *argv, t_node **tail);
t_node	*check_split(int length, char **split_result, t_node **tail);
void	check_for_minus_or_plus(char *str, int *has_minus_or_plus);
void	free_double_pointer(char **ptr, int i);
long	convert_to_long(char *str);
int		check_for_int_range(long num);
t_node	*add_node_at_end(int content, t_node **tail);
t_node	*create_node(int content);
int		get_length_of_list(t_node *tail);
t_node	*check_for_duplication(t_node *tail);
void	free_list(t_node	*tail, void (*del)(void *));
void	delete_node_content(void *content);
int		check_for_digits(t_node *tail, char	*arg, int i);
void	*throw_an_error(void);
void	rotate(t_lists *lists, t_stack name);
void	reverse_rotate(t_lists *lists, t_stack name);
void	swap(t_lists *lists, t_stack name);
t_node	*push(t_lists *lists, t_stack name);
t_node	*pop(t_node **source);
void	sort_three_or_less_numbers(t_lists *lists, t_stack name);
void	sort_four_or_five_numbers(t_lists *lists, t_stack name);
t_node	*get_tail_of_list(t_lists lists, t_stack name);
t_stack	get_other_stack_name(t_stack name);
t_node	*get_other_stack_tail(t_lists lists, t_stack name);
t_num	find_max(t_node *a);
t_num	find_min(t_node *a);
int		calc_absolute(int a, int b);
void	sort_six_or_more_numbers(t_lists *lists, t_stack name);
t_node	*get_ptr_to_node(t_node *tail, int content);
void	push_min(t_lists *lists, t_stack name);
void	push_max(t_lists *lists, t_stack name);
void	push_not_min_max(t_lists *lists, t_stack name, int num, t_node *pos);
t_node	*find_correct_pos(t_lists *lists, t_stack name, int num_to_push);
void	push_num_to_correct_pos(t_lists *lists, t_stack name, int num_to_push);
int		check_distance_to_top(t_node *tail, t_node *min_content);
int		check_distance_to_bottom(t_node *tail, t_node *min_content);
void	move_node_to_top(t_lists *lists, t_stack name, t_node *node_to_top);
int		calc_min_num(int a, int b);
int		calc_max_num(int a, int b);
void	sort_from_top(t_lists *lists, t_stack name);
int		check_if_already_sorted(t_lists lists, t_stack name);
int		compare_cur_num_vs_max(t_lists *lists, t_stack name, t_node *cur_node);
int		compare_cur_num_vs_min(t_lists *lists, t_stack name, t_node *cur_node);
int		simu_move_a_node_to_top(t_lists *lists, t_stack name, t_node *node);
int		simu_move_a_node_to_bottom(t_lists *lists, t_stack name, t_node *node);
int		simu_stack_move(t_lists *lists, t_stack name, t_node *tar, t_node *cur);
void	count_moves_for_cur_node(t_lists *lists, t_stack name, t_node *cur);
void	find_total_move_num(t_lists *lists, t_stack name);
t_node	*find_the_best_node(t_lists *lists, t_stack name);
void	handle_best_node_alone_move(t_lists *lists, t_stack name, t_node *best);
void	handle_tar_node_alone_move(t_lists *lists, t_stack name, t_node *best);
void	handle_no_alone_move(t_lists *lists, t_node *best_node);
void	handle_rr_or_rrr(t_lists *lists, t_stack name, t_node *best_node);
void	one_stack_r(t_lists *lists, t_stack name, int best_dist, int tar_dist);
void	best_r_tar_rev_r(t_lists *lists, t_stack name, int best_d, int tar_d);
void	one_stack_rev_r(t_lists *lists, t_stack name, int best_dist, int tar_d);
void	best_rev_r_tar_r(t_lists *lists, t_stack name, int best_d, int tar_d);
void	move_both_stacks(t_lists *lists, t_stack name);
void	set_has_rr_or_rrr(t_node *current_node, t_node *target_node);
void	change_has_rr_or_rrr(t_node *current_node, t_node *target_node);
t_node	*find_target_node(t_lists *lists, t_stack name, t_node *current_node);
void	handle_both_dist_same(t_node *current_node, t_node *target_node);

#endif
