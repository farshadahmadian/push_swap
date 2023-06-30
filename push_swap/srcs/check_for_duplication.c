/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_duplication.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:10:20 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/28 16:19:20 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*check_for_content_duplication(t_node *tail, t_node **temp, int length)
{
	int	j;

	j = 0;
	while (j < length - 1)
	{
		if (tail->content == (*temp)->content)
		{
			free_list(tail, delete_node_content);
			throw_an_error();
			return (NULL);
		}
		*temp = (*temp)->next;
		j++;
	}
	return (tail);
}

t_node	*check_for_duplication(t_node *tail)
{	
	int		i;
	int		length;
	t_node	*temp;

	i = 0;
	temp = tail->next;
	length = get_length_of_list(tail);
	while (i < length)
	{
		if (!check_for_content_duplication(tail, &temp, length))
			return (NULL);
		tail = tail->next;
		temp = tail->next;
		i++;
	}
	return (tail);
}
