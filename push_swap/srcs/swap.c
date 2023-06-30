/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:10:43 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/28 20:39:58 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	switch_nodes(t_node **tail)
{
	t_node	*temp;
	t_node	*temp2;
	int		length;

	if (!(*tail))
		return (0);
	length = get_length_of_list(*tail);
	if (!length || length == 1)
		return (0);
	temp = (*tail)->next;
	temp2 = temp->next;
	if (temp2 != (*tail))
	{
		temp->next = temp2->next;
		temp2->next = temp;
		(*tail)->next = temp2;
	}
	else
		(*tail) = temp;
	return (1);
}

void	swap(t_lists *lists, t_stack name)
{
	int	has_list_a_node;
	int	has_list_b_node;

	has_list_a_node = 0;
	has_list_b_node = 0;
	if (name == A)
	{
		if (switch_nodes(&(lists->a)))
			ft_printf("sa\n");
	}
	else if (name == B)
	{
		if (switch_nodes(&(lists->b)))
			ft_printf("sb\n");
	}
	else if (name == BOTH)
	{
		has_list_a_node = switch_nodes(&(lists->a));
		has_list_b_node = switch_nodes(&(lists->b));
		if (has_list_a_node || has_list_b_node)
			ft_printf("ss\n");
	}
}
