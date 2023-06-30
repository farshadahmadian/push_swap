/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_no_rr_or_rrr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:07:41 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/28 19:06:56 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	one_stack_r(t_lists *lists, t_stack name, int best_n_dist, int tar_dist)
{
	int		i;
	t_stack	other_stack_name;

	i = 0;
	other_stack_name = get_other_stack_name(name);
	while (i < best_n_dist)
	{
		rotate(lists, name);
		i++;
	}
	i = 0;
	while (i < tar_dist)
	{
		rotate(lists, other_stack_name);
		i++;
	}
}

void	best_r_tar_rev_r(t_lists *lists, t_stack name, int best_dist, int tar_d)
{
	int		i;
	t_stack	other_stack_name;

	i = 0;
	other_stack_name = get_other_stack_name(name);
	while (i < best_dist)
	{
		rotate(lists, name);
		i++;
	}
	i = 0;
	while (i < tar_d)
	{
		reverse_rotate(lists, other_stack_name);
		i++;
	}
}

void	one_stack_rev_r(t_lists *lists, t_stack name, int best_dist, int tar_d)
{
	int		i;
	t_stack	other_stack_name;

	i = 0;
	other_stack_name = get_other_stack_name(name);
	while (i < best_dist)
	{
		reverse_rotate(lists, name);
		i++;
	}
	i = 0;
	while (i < tar_d)
	{
		reverse_rotate(lists, other_stack_name);
		i++;
	}
}

void	best_rev_r_tar_r(t_lists *lists, t_stack name, int best_dist, int tar_d)
{
	int		i;
	t_stack	other_stack_name;

	i = 0;
	other_stack_name = get_other_stack_name(name);
	while (i < best_dist)
	{
		reverse_rotate(lists, name);
		i++;
	}
	i = 0;
	while (i < tar_d)
	{
		rotate(lists, other_stack_name);
		i++;
	}
}

void	move_both_stacks(t_lists *lists, t_stack name)
{	
	t_node	*best;
	int		best_node_best_dist;
	int		target_best_dist;

	if (!get_tail_of_list(*lists, name))
		return ;
	best = find_the_best_node(lists, name);
	best_node_best_dist = best->details.best_dist;
	target_best_dist = best->details.tar_best_dist;
	if (best->details.has_rr_or_rrr)
		handle_rr_or_rrr(lists, name, best);
	else if (best->details.move_type == ROTATE
		&& best->details.tar_move_type == ROTATE)
		one_stack_r(lists, name, best_node_best_dist, target_best_dist);
	else if (best->details.move_type == ROTATE
		&& best->details.tar_move_type == REV_ROTATE)
		best_r_tar_rev_r(lists, name, best_node_best_dist, target_best_dist);
	else if (best->details.move_type == REV_ROTATE
		&& best->details.tar_move_type == REV_ROTATE)
		one_stack_rev_r(lists, name, best_node_best_dist, target_best_dist);
	else if (best->details.move_type == REV_ROTATE
		&& best->details.tar_move_type == ROTATE)
		best_rev_r_tar_r(lists, name, best_node_best_dist, target_best_dist);
}
