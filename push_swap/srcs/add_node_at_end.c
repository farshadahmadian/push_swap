/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node_at_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:10:27 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/28 16:14:02 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*add_node_at_end(int content, t_node **tail)
{
	t_node	*node_ptr;
	t_node	*first;

	node_ptr = create_node(content);
	if (!node_ptr)
		return (NULL);
	first = (*tail)->next;
	(*tail)->next = node_ptr;
	(*tail) = node_ptr;
	(*tail)->next = first;
	return (*tail);
}
