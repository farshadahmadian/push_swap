/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_equal_upward_and_downward_distances.        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:16:01 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/28 16:30:59 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	handle_both_dist_same(t_node *current_node, t_node *target_node)
{
	if (current_node->details.is_both_dist_same)
		current_node->details.move_type = target_node->details.move_type;
	else if (target_node->details.is_both_dist_same)
		target_node->details.move_type = current_node->details.move_type;
}
