/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:49:08 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/28 19:46:53 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	int	move_tail_to_previous_node(t_node **tail)
{
	t_node	*temp;
	int		length;

	if (!(*tail))
		return (0);
	length = get_length_of_list(*tail);
	if (!length || length == 1)
		return (0);
	temp = *tail;
	while ((*tail)->next != temp)
	{
		(*tail) = (*tail)->next;
	}
	return (1);
}

void	reverse_rotate(t_lists *lists, t_stack name)
{
	int	has_list_a_node;
	int	has_list_b_node;

	has_list_a_node = 0;
	has_list_b_node = 0;
	if (name == A)
	{
		if (move_tail_to_previous_node(&((*lists).a)))
			ft_printf("rra\n");
	}
	else if (name == B)
	{
		if (move_tail_to_previous_node(&((*lists).b)))
			ft_printf("rrb\n");
	}
	else
	{
		has_list_a_node = move_tail_to_previous_node(&((*lists).a));
		has_list_b_node = move_tail_to_previous_node(&((*lists).b));
		if (has_list_a_node || has_list_b_node)
			ft_printf("rrr\n");
	}
}
