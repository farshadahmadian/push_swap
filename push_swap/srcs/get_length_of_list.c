/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length_of_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:25:29 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/28 15:38:46 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_length_of_list(t_node *tail)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = tail;
	while (tail != temp -> next)
	{
		i++;
		temp = temp -> next;
	}
	return (i + 1);
}
