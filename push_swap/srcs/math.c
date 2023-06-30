/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 09:09:19 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/28 19:37:35 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	calc_absolute(int a, int b)
{
	if ((a - b) >= 0)
		return (a - b);
	else
		return (b - a);
}

t_num	find_max(t_node *a)
{
	int		i;
	int		length_of_a;
	t_num	max;

	a = a->next;
	i = 0;
	max.num = a->content;
	max.i = 0;
	length_of_a = get_length_of_list(a);
	while (i < length_of_a)
	{
		if (a->content > max.num)
		{
			max.num = a->content;
			max.i = i;
		}
		a = a->next;
		i++;
	}
	return (max);
}

t_num	find_min(t_node *a)
{
	int		i;
	int		length_of_a;
	t_num	min;

	a = a->next;
	i = 0;
	min.num = a->content;
	min.i = 0;
	length_of_a = get_length_of_list(a);
	while (i < length_of_a)
	{
		if (a->content < min.num)
		{
			min.num = a->content;
			min.i = i;
		}
		a = a->next;
		i++;
	}
	return (min);
}

int	calc_min_num(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int	calc_max_num(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}
