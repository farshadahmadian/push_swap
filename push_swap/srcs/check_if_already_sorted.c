/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_already_sorted.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:41:44 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/28 15:38:46 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_if_already_sorted(t_lists lists, t_stack name)
{
	t_node	*tail;
	t_node	*temp;
	int		length;
	int		i;

	tail = get_tail_of_list(lists, name);
	if (!tail)
		return (0);
	temp = tail->next;
	length = get_length_of_list(tail);
	i = 0;
	while (i < length - 1)
	{
		if (temp->content > temp->next->content)
			return (1);
		i++;
		temp = temp->next;
	}
	return (0);
}
