/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_the_best_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 09:34:33 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/28 19:46:07 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_max(t_lists *lists, t_stack name)
{
	t_node	*tail;
	t_node	*temp;
	int		i;
	int		length;
	t_num	max;

	i = 0;
	tail = get_tail_of_list(*lists, name);
	length = get_length_of_list(tail);
	max = find_max(tail);
	temp = tail->next;
	while (i < length)
	{
		if (temp->content == max.num)
		{
			rotate(lists, name);
			push(lists, name);
			length++;
			return ;
		}
		i++;
		rotate(lists, name);
		temp = temp -> next;
	}	
}

void	push_min(t_lists *lists, t_stack name)
{
	t_node	*tail;
	t_node	*temp;
	int		i;
	int		length;
	t_num	min;

	i = 0;
	tail = get_tail_of_list(*lists, name);
	length = get_length_of_list(tail);
	min = find_min(tail);
	temp = tail->next;
	while (i < length)
	{
		if (temp->content == min.num)
		{
			push(lists, name);
			length++;
			return ;
		}
		i++;
		rotate(lists, name);
		temp = temp -> next;
	}
}

void	push_not_min_max(t_lists *lists, t_stack name, int num, t_node *pos)
{
	t_node	*tail;
	t_node	*temp;
	int		i;

	i = 0;
	tail = get_tail_of_list(*lists, name);
	temp = tail->next;
	while (i < get_length_of_list(tail))
	{
		if (temp == pos)
		{
			if ((pos->content < num))
			{
				rotate(lists, name);
				push(lists, name);
			}
			else if ((pos->content > num))
				push(lists, name);
			return ;
		}
		i++;
		rotate(lists, name);
		temp = temp -> next;
	}
}

t_node	*find_correct_pos(t_lists *lists, t_stack name, int num_to_be_pushed)
{
	int		subtract;
	t_node	*position;
	t_node	*temp;
	t_node	*tail;
	int		i;

	subtract = 0;
	tail = get_tail_of_list(*lists, name);
	temp = tail->next;
	position = temp;
	subtract = calc_absolute(num_to_be_pushed, temp->content);
	i = 0;
	while (i < get_length_of_list(tail))
	{
		if (calc_absolute(num_to_be_pushed, temp->content) < subtract)
		{
			subtract = calc_absolute(num_to_be_pushed, temp->content);
			position = temp;
		}
		i++;
		temp = temp->next;
	}
	return (position);
}

void	push_num_to_correct_pos(t_lists *lists, t_stack name, int num_to_push)
{
	t_num	max;
	t_num	min;
	t_node	*tail;
	t_node	*position;

	if (!lists)
		return ;
	tail = get_tail_of_list(*lists, name);
	max = find_max(tail);
	min = find_min(tail);
	if (num_to_push > max.num)
		push_max(lists, name);
	else if (num_to_push < min.num)
		push_min(lists, name);
	else
	{
		position = find_correct_pos(lists, name, num_to_push);
		push_not_min_max(lists, name, num_to_push, position);
	}
}
