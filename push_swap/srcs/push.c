/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:27:55 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/28 19:41:49 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*pop(t_node **source)
{
	t_node	*head;
	int		length;

	if (*source)
		length = get_length_of_list(*source);
	else
		length = 0;
	if (!(*source) || !length)
		return (NULL);
	head = (*source)->next;
	(*source)->next = head->next;
	head->next = head;
	length--;
	if (!length)
		*source = NULL;
	return (head);
}

t_node	*move_node_to_other_list(t_node **dest, t_node **src)
{
	t_node	*popped;
	int		length;

	if (*dest)
		length = get_length_of_list(*dest);
	else
		length = 0;
	popped = pop(src);
	if (!popped)
		return (popped);
	if (!(*dest))
	{
		*dest = popped;
		(*dest)->next = *dest;
		length++;
	}
	else
	{
		popped->next = (*dest)->next;
		(*dest)->next = popped;
		length++;
	}
	return (popped);
}

t_node	*push(t_lists *lists, t_stack name)
{
	t_node	*popped;

	popped = NULL;
	if (name == A)
	{
		popped = move_node_to_other_list(&((*lists).a), &((*lists).b));
		if (!popped)
			return (popped);
		ft_printf("pa\n");
	}
	else if (name == B)
	{
		popped = move_node_to_other_list(&((*lists).b), &((*lists).a));
		if (!popped)
			return (popped);
		ft_printf("pb\n");
	}
	return (popped);
}
