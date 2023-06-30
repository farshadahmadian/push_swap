/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rr_or_rrr_set.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:11:55 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/28 19:35:31 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_has_rr_or_rrr(t_node *current_node, t_node *target_node)
{
	int	has_both_move;
	int	has_same_move_type;
	int	cur_node_best_dist;
	int	tar_node_best_dist;

	cur_node_best_dist = current_node->details.best_dist;
	tar_node_best_dist = target_node->details.best_dist;
	has_both_move = (cur_node_best_dist > 0 && tar_node_best_dist > 0);
	has_same_move_type = current_node->details.move_type
		== target_node->details.move_type;
	if (has_both_move && has_same_move_type)
	{
		current_node->details.has_rr_or_rrr = 1;
		current_node->details.num_of_rr_or_rrr
			= calc_min_num(cur_node_best_dist, tar_node_best_dist);
		if (cur_node_best_dist > tar_node_best_dist)
			current_node->details.has_alone_move = 1;
		else if (cur_node_best_dist < tar_node_best_dist)
			current_node->details.has_alone_move = -1;
		current_node->details.num_of_alone_moves
			= calc_absolute(cur_node_best_dist, tar_node_best_dist);
	}
}

void	change_has_rr_or_rrr(t_node *current_node, t_node *target_node)
{
	int	has_one_no_move;
	int	has_diff_move_types;
	int	cur_node_best_dist;
	int	tar_node_best_dist;

	cur_node_best_dist = current_node->details.best_dist;
	tar_node_best_dist = target_node->details.best_dist;
	has_one_no_move = (cur_node_best_dist == 0 || tar_node_best_dist == 0);
	has_diff_move_types = current_node->details.move_type
		!= target_node->details.move_type;
	if (current_node->details.has_rr_or_rrr)
	{
		if (has_one_no_move || has_diff_move_types)
		{
			current_node->details.has_rr_or_rrr = 0;
			current_node->details.num_of_rr_or_rrr = 0;
			current_node->details.has_alone_move = 0;
			current_node->details.num_of_alone_moves = 0;
		}
	}
}
