/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:58:16 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/28 16:38:30 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	count_moves_for_cur_node(t_lists *lists, t_stack name, t_node *cur)
{
	t_node	*tail;

	tail = get_tail_of_list(*lists, name);
	if (!tail)
		return ;
	cur->details.best_dist = simu_move_a_node_to_top(lists, name, cur);
}

void	find_total_move_num(t_lists *lists, t_stack name)
{
	int		i;
	t_node	*cur_node;
	int		cur_node_dist;
	int		tar_node_dist;
	int		max_of_dists;

	if (!lists)
		return ;
	i = 0;
	cur_node = get_tail_of_list(*lists, name)->next;
	while (i < get_length_of_list(get_tail_of_list(*lists, name)))
	{
		cur_node_dist = cur_node->details.best_dist;
		tar_node_dist = cur_node->details.tar_best_dist;
		max_of_dists = calc_max_num(cur_node_dist, tar_node_dist);
		if (cur_node->details.has_rr_or_rrr)
			cur_node->details.total_move = max_of_dists + 1;
		else
			cur_node->details.total_move = cur_node_dist + tar_node_dist + 1;
		i++;
		cur_node = cur_node->next;
	}
}

t_node	*find_the_best_node(t_lists *lists, t_stack name)
{
	t_node	*tail;
	int		i;
	int		lowest_move_num;
	t_node	*current_node;
	t_node	*best_node;

	if (!lists)
		return (NULL);
	tail = get_tail_of_list(*lists, name);
	i = 0;
	current_node = tail->next;
	lowest_move_num = current_node->details.total_move;
	best_node = current_node;
	while (i++ < get_length_of_list(tail))
	{
		if (current_node->details.total_move < lowest_move_num)
		{
			lowest_move_num = current_node->details.total_move;
			best_node = current_node;
		}
		current_node = current_node->next;
	}
	return (best_node);
}
