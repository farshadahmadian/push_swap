/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pointer_to_a_node.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 09:32:51 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/28 18:34:29 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*get_ptr_to_node(t_node *tail, int content)
{
	t_node	*temp;
	int		i;
	int		length;

	i = 0;
	temp = tail->next;
	length = get_length_of_list(tail);
	while (i < length)
	{
		if (temp->content == content)
			return (temp);
		temp = temp->next;
		i++;
	}
	return (temp);
}
