/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_six_or_more_numbers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 09:14:45 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/28 20:34:36 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_all_nodes(t_lists *lists, t_stack name)
{
	t_node	*tail;
	t_stack	other_stack_name;
	t_node	*target_node;
	t_node	*current_node;
	int		j;

	tail = get_tail_of_list(*lists, name);
	other_stack_name = get_other_stack_name(name);
	if (!tail)
		return ;
	j = 0;
	current_node = tail->next;
	while (j < get_length_of_list(tail))
	{
		count_moves_for_cur_node(lists, name, current_node);
		target_node = find_target_node(lists, name, current_node);
		handle_both_dist_same(current_node, target_node);
		set_has_rr_or_rrr(current_node, target_node);
		change_has_rr_or_rrr(current_node, target_node);
		current_node->target_node = target_node;
		current_node->details.tar_best_dist = target_node->details.best_dist;
		current_node->details.tar_move_type = target_node->details.move_type;
		current_node = current_node -> next;
		j++;
	}
}

void	push_all_efficiently(t_lists *lists, t_stack name)
{
	t_stack	other_stack_name;
	t_node	*tail;
	int		length;

	other_stack_name = get_other_stack_name(name);
	tail = get_tail_of_list(*lists, name);
	length = get_length_of_list(tail);
	while (length)
	{
		check_all_nodes(lists, name);
		find_total_move_num(lists, name);
		move_both_stacks(lists, name);
		push(lists, other_stack_name);
		tail = get_tail_of_list(*lists, name);
		if (!tail)
			break ;
	}
}

void	push_all_back(t_lists *lists, t_stack name)
{
	t_node	*other_stack_tail;
	int		other_stack_length;
	t_node	*other_stack_max_p;
	int		other_stack_max;
	int		i;

	other_stack_tail = get_other_stack_tail(*lists, name);
	other_stack_length = get_length_of_list(other_stack_tail);
	other_stack_max = find_max(other_stack_tail).num;
	other_stack_max_p = get_ptr_to_node(other_stack_tail, other_stack_max);
	i = 0;
	while (i < other_stack_length)
	{
		move_node_to_top(lists, get_other_stack_name(name), other_stack_max_p);
		i++;
	}
	i = 0;
	while (i < other_stack_length)
	{
		push(lists, name);
		i++;
	}
}

void	sort_six_or_more_numbers(t_lists *lists, t_stack name)
{
	t_stack	other_stack_name;
	t_node	*tail;
	int		i;

	i = 0;
	tail = get_tail_of_list(*lists, name);
	if (!tail || get_length_of_list(tail) < 6)
		return ;
	other_stack_name = get_other_stack_name(name);
	push(lists, other_stack_name);
	push(lists, other_stack_name);
	push_all_efficiently(lists, name);
	push_all_back(lists, name);
	return ;
}
