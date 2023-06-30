/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 08:49:40 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/28 19:47:19 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	move_tail_to_first_node(t_node **tail)
{
	int	length;

	if (!(*tail))
		return (0);
	length = get_length_of_list(*tail);
	if (!length || length == 1)
		return (0);
	*tail = (*tail)->next;
	return (1);
}

void	rotate(t_lists *lists, t_stack name)
{
	int	has_list_a_node;
	int	has_list_b_node;

	has_list_a_node = 0;
	has_list_b_node = 0;
	if (name == A)
	{
		if (move_tail_to_first_node(&(lists->a)))
			ft_printf("ra\n");
	}
	else if (name == B)
	{
		if (move_tail_to_first_node(&(lists->b)))
			ft_printf("rb\n");
	}
	else if (name == BOTH)
	{
		has_list_a_node = move_tail_to_first_node(&(lists->a));
		has_list_b_node = move_tail_to_first_node(&(lists->b));
		if (has_list_a_node || has_list_b_node)
			ft_printf("rr\n");
	}	
}
