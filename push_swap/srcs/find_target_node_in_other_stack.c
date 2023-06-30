/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target_node_in_other_stack.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:18:38 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/28 18:38:10 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*find_target_node(t_lists *lists, t_stack name, t_node *cur)
{
	t_stack	other_stack_name;
	t_node	*other_stack_tail;
	t_node	*other_stack_max_node;
	t_node	*target_node;
	int		max;

	other_stack_name = get_other_stack_name(name);
	other_stack_tail = get_other_stack_tail(*lists, name);
	max = find_max(other_stack_tail).num;
	other_stack_max_node = get_ptr_to_node(other_stack_tail, max);
	if (compare_cur_num_vs_max(lists, name, cur)
		|| compare_cur_num_vs_min(lists, name, cur))
	{
		target_node = other_stack_max_node;
		simu_move_a_node_to_top(lists, other_stack_name, other_stack_max_node);
	}
	else
	{
		target_node = find_correct_pos(lists, other_stack_name, cur->content);
		simu_stack_move(lists, other_stack_name, target_node, cur);
	}
	return (target_node);
}
