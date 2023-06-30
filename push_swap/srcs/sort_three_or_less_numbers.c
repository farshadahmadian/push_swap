/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_or_less_numbers.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:32:18 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/28 20:36:00 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_two_numbers(t_lists *lists, t_stack name, t_num max, t_num min)
{		
	if (max.i < min.i)
		swap(lists, name);
}

void	sort_three_numbers(t_lists *lists, t_stack name, t_num max, t_num min)
{
	t_node	*tail;

	tail = get_tail_of_list(*lists, name);
	if (max.i == 0 && min.i == 1)
		rotate(lists, name);
	else if (max.i == 0 && min.i == 2)
	{
		rotate(lists, name);
		swap(lists, name);
	}
	else if (max.i == 1 && min.i == 0)
	{
		reverse_rotate(lists, name);
		swap(lists, name);
	}
	else if (max.i == 1 && min.i == 2)
		reverse_rotate(lists, name);
	else if (max.i == 2 && min.i == 1)
		swap(lists, name);
}

void	sort_three_or_less_numbers(t_lists *lists, t_stack name)
{
	t_num	min;
	t_num	max;
	t_node	*tail;
	int		length;

	tail = get_tail_of_list(*lists, name);
	if (!tail)
		length = 0;
	else
		length = get_length_of_list(tail);
	if (!(length == 2 || length == 3))
		return ;
	max = find_max(tail);
	min = find_min(tail);
	if (length == 2)
	{
		sort_two_numbers(lists, name, max, min);
		return ;
	}
	sort_three_numbers(lists, name, max, min);
}
