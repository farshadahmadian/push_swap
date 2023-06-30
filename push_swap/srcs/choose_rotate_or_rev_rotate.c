/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_rotate_or_rev_rotate.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 09:39:25 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/28 20:34:36 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_distance_to_bottom(t_node *tail, t_node *min_content)
{
	int		i;
	int		length;
	t_node	*temp;

	i = 0;
	length = get_length_of_list(tail);
	temp = min_content;
	while (i < length)
	{
		if (temp == tail)
		{
			min_content->details.dist_to_bottom = i;
			return (i);
		}
		i++;
		temp = temp->next;
	}
	return (i);
}

int	check_distance_to_top(t_node *tail, t_node *min_content)
{
	int		i;
	int		length;
	t_node	*temp;

	i = 0;
	length = get_length_of_list(tail);
	temp = tail->next;
	while (i < length)
	{
		if (temp == min_content)
		{
			min_content->details.dist_to_top = i;
			return (i);
		}
		i++;
		temp = temp->next;
	}
	return (i);
}

void	move_node_to_top(t_lists *lists, t_stack name, t_node *node_to_top)
{
	int		distance_to_top;
	int		distance_to_bottom;
	int		best_distance;
	int		i;
	t_node	*tail;

	tail = get_tail_of_list(*lists, name);
	i = 0;
	distance_to_top = check_distance_to_top(tail, node_to_top);
	distance_to_bottom = check_distance_to_bottom(tail, node_to_top);
	if (distance_to_bottom < distance_to_top)
	{
		best_distance = distance_to_bottom;
		while (i++ <= best_distance)
			reverse_rotate(lists, name);
	}
	else
	{
		best_distance = distance_to_top;
		while (i++ < best_distance)
			rotate (lists, name);
	}
}
