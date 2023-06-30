/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:44:29 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/28 18:39:54 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_list(t_node	*tail, void (*del)(void *))
{
	int		size_of_list;
	int		i;
	t_node	*temp;

	i = 0;
	if (!tail)
		return ;
	size_of_list = get_length_of_list(tail);
	while (i < size_of_list)
	{
		temp = tail;
		tail = (tail)->next;
		del(&(temp->content));
		free(temp);
		i++;
	}
}
