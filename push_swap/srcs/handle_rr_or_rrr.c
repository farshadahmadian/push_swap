/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rr_or_rrr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:01:51 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/28 19:12:37 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	handle_best_node_alone_move(t_lists *lists, t_stack name, t_node *best)
{
	int	i;

	i = 0;
	if (best->details.has_alone_move == 1 && best->details.move_type == ROTATE)
	{
		while (i++ < best->details.num_of_rr_or_rrr)
			rotate(lists, BOTH);
		i = 0;
		while (i++ < best->details.num_of_alone_moves)
			rotate(lists, name);
	}
	else if (best->details.has_alone_move == 1
		&& best->details.move_type == REV_ROTATE)
	{
		while (i++ < best->details.num_of_rr_or_rrr)
			reverse_rotate(lists, BOTH);
		i = 0;
		while (i++ < best->details.num_of_alone_moves)
			reverse_rotate(lists, name);
	}
}

void	handle_tar_node_alone_move(t_lists *lists, t_stack name, t_node *best)
{
	int		i;
	t_stack	other_stack_name;

	i = 0;
	other_stack_name = get_other_stack_name(name);
	if (best->details.has_alone_move == -1 && best->details.move_type == ROTATE)
	{
		while (i++ < best->details.num_of_rr_or_rrr)
			rotate(lists, BOTH);
		i = 0;
		while (i++ < best->details.num_of_alone_moves)
			rotate(lists, other_stack_name);
	}
	else if (best->details.has_alone_move == -1
		&& best->details.move_type == REV_ROTATE)
	{
		while (i++ < best->details.num_of_rr_or_rrr)
			reverse_rotate(lists, BOTH);
		i = 0;
		while (i++ < best->details.num_of_alone_moves)
			reverse_rotate(lists, other_stack_name);
	}
}

void	handle_no_alone_move(t_lists *lists, t_node *best_node)
{
	int	i;

	i = 0;
	if (best_node->details.has_alone_move == 0
		&& best_node->details.move_type == ROTATE)
	{
		while (i < best_node->details.num_of_rr_or_rrr)
		{
			rotate(lists, BOTH);
			i++;
		}
	}
	else if (best_node->details.has_alone_move == 0
		&& best_node->details.move_type == REV_ROTATE)
	{
		while (i < best_node->details.num_of_rr_or_rrr)
		{
			reverse_rotate(lists, BOTH);
			i++;
		}
	}
}

void	handle_rr_or_rrr(t_lists *lists, t_stack name, t_node *best_node)
{	
	handle_best_node_alone_move(lists, name, best_node);
	handle_tar_node_alone_move(lists, name, best_node);
	handle_no_alone_move(lists, best_node);
}
