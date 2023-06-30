/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_movement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:50:53 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/28 19:51:50 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	simu_move_a_node_to_top(t_lists *lists, t_stack name, t_node *node_to_top)
{
	int		distance_to_top;
	int		distance_to_bottom;
	int		best_distance;
	t_node	*tail;

	tail = get_tail_of_list(*lists, name);
	distance_to_top = check_distance_to_top(tail, node_to_top);
	distance_to_bottom = check_distance_to_bottom(tail, node_to_top);
	if (distance_to_bottom < distance_to_top)
	{
		best_distance = distance_to_bottom + 1;
		node_to_top->details.move_type = REV_ROTATE;
		node_to_top->details.best_dist = best_distance;
	}
	else
	{
		best_distance = distance_to_top;
		node_to_top->details.move_type = ROTATE;
		node_to_top->details.best_dist = best_distance;
	}
	if (distance_to_top == distance_to_bottom + 1)
		node_to_top->details.is_both_dist_same = 1;
	else
		node_to_top->details.is_both_dist_same = 0;
	return (best_distance);
}

int	simu_move_a_node_to_bottom(t_lists *lists, t_stack name, t_node *node)
{
	int		distance_to_top;
	int		distance_to_bottom;
	int		best_distance;
	t_node	*tail;

	tail = get_tail_of_list(*lists, name);
	distance_to_top = check_distance_to_top(tail, node);
	distance_to_bottom = check_distance_to_bottom(tail, node);
	if (distance_to_top < distance_to_bottom)
	{
		best_distance = distance_to_top + 1;
		node->details.move_type = ROTATE;
		node->details.best_dist = best_distance;
	}
	else
	{
		best_distance = distance_to_bottom;
		node->details.move_type = REV_ROTATE;
		node->details.best_dist = best_distance;
	}
	if (distance_to_bottom == distance_to_top + 1)
		node->details.is_both_dist_same = 1;
	else
		node->details.is_both_dist_same = 0;
	return (best_distance);
}

int	simu_stack_move(t_lists *lists, t_stack name, t_node *tar, t_node *cur)
{	
	int	movement_number;

	movement_number = 0;
	if (cur->content < tar->content)
		movement_number = simu_move_a_node_to_bottom(lists, name, tar);
	else if (cur->content > tar->content)
		movement_number = simu_move_a_node_to_top(lists, name, tar);
	return (movement_number);
}
