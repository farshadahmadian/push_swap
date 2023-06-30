/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:10:37 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/28 16:22:30 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*create_node(int content)
{
	t_node	*node_ptr;

	node_ptr = calloc(1, sizeof(t_node));
	if (!node_ptr)
		return (NULL);
	node_ptr -> content = content;
	node_ptr -> next = node_ptr;
	return (node_ptr);
}
