/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_with_min_and_max.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:34:24 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/28 16:22:00 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	compare_cur_num_vs_max(t_lists *lists, t_stack name, t_node *curr_node)
{
	t_node	*tail;
	t_num	max;

	max = find_max(get_other_stack_tail(*lists, name));
	tail = get_tail_of_list(*lists, name);
	if (!tail)
		return (0);
	if (curr_node->content > max.num)
	{
		return (1);
	}
	return (0);
}

int	compare_cur_num_vs_min(t_lists *lists, t_stack name, t_node *curr_node)
{
	t_node	*tail;
	t_num	min;

	min = find_min(get_other_stack_tail(*lists, name));
	tail = get_tail_of_list(*lists, name);
	if (!tail)
		return (0);
	if (curr_node->content < min.num)
		return (1);
	return (0);
}
