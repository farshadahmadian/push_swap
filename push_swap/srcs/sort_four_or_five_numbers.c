/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_or_five_numbers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:51:46 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/28 20:38:44 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_from_top(t_lists *lists, t_stack name)
{
	t_num	min;
	t_node	*min_content_node;
	t_node	*tail;

	tail = get_tail_of_list(*lists, name);
	min = find_min(tail);
	min_content_node = get_ptr_to_node(tail, min.num);
	move_node_to_top(lists, name, min_content_node);
}

void	keep_three_greatest_nums(t_lists *lists, t_stack name)
{
	int		i;
	t_node	*tail;
	int		length;
	t_stack	other_stack_name;
	t_node	*min_ptr;

	i = 0;
	tail = get_tail_of_list(*lists, name);
	if (!tail)
		return ;
	length = get_length_of_list(tail);
	other_stack_name = get_other_stack_name(name);
	i = 0;
	while (i < length - 3)
	{
		tail = get_tail_of_list(*lists, name);
		min_ptr = get_ptr_to_node(tail, find_min(tail).num);
		move_node_to_top(lists, name, min_ptr);
		push(lists, other_stack_name);
		i++;
	}
}

void	sort_four_or_five_numbers(t_lists *lists, t_stack name)
{
	t_node	*tail;
	t_node	*other_stack_tail;
	t_stack	other_stack_name;
	int		length;

	tail = get_tail_of_list(*lists, name);
	if (!tail)
		return ;
	length = get_length_of_list(tail);
	if (length != 5 && length != 4)
		return ;
	keep_three_greatest_nums(lists, name);
	sort_three_or_less_numbers(lists, name);
	other_stack_name = get_other_stack_name(name);
	other_stack_tail = get_other_stack_tail(*lists, name);
	push_num_to_correct_pos(lists, name, other_stack_tail->next->content);
	push_num_to_correct_pos(lists, name, other_stack_tail->next->content);
	sort_from_top(lists, name);
}
