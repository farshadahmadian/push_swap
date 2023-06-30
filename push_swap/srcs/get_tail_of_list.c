/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tail_of_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:38:20 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/28 18:55:39 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*get_tail_of_list(t_lists lists, t_stack name)
{
	t_node	*tail;

	tail = NULL;
	if (name == A)
		tail = lists.a;
	else if (name == B)
		tail = lists.b;
	return (tail);
}

t_node	*get_other_stack_tail(t_lists lists, t_stack name)
{
	t_node	*other_stack;

	other_stack = NULL;
	if (name == A)
		other_stack = lists.b;
	else if (name == B)
		other_stack = lists.a;
	return (other_stack);
}

t_stack	get_other_stack_name(t_stack name)
{
	t_stack	other_stack_name;

	other_stack_name = NO_STACK;
	if (name == A)
		other_stack_name = B;
	else if (name == B)
		other_stack_name = A;
	return (other_stack_name);
}
