/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv_or_split.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 11:02:09 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/28 16:15:25 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	skip_sign(int *has_minus_or_plus, int *index)
{
	if (*has_minus_or_plus)
	{
		*index = 1;
		*has_minus_or_plus = 0;
	}
}

static void	insert_input_to_list(long converted_to_long, t_node **tail)
{
	int	converted_to_int;

	converted_to_int = (int)converted_to_long;
	if (!(*tail))
		*tail = create_node(converted_to_int);
	else
		*tail = add_node_at_end(converted_to_int, tail);
}

t_node	*check_strings(t_node **tail, char *string, int *has_minus_or_plus)
{
	int		index;
	long	converted_to_long;

	index = 0;
	check_for_minus_or_plus(string, has_minus_or_plus);
	skip_sign(has_minus_or_plus, &index);
	if (!check_for_digits(*tail, string, index))
		return (NULL);
	converted_to_long = convert_to_long(string);
	if (check_for_int_range(converted_to_long))
		insert_input_to_list(converted_to_long, tail);
	else
	{
		free_list(*tail, delete_node_content);
		throw_an_error();
		return (NULL);
	}
	return (*tail);
}

t_node	*check_argv(char *argv, t_node **tail)
{
	int		has_minus_or_plus;

	has_minus_or_plus = 0;
	if (!check_strings(tail, argv, &has_minus_or_plus))
		return (NULL);
	return (*tail);
}

t_node	*check_split(int length, char **split_result, t_node **tail)
{
	int		i;
	int		has_minus_or_plus;

	i = 0;
	has_minus_or_plus = 0;
	while (i < length)
	{
		if (!check_strings(tail, split_result[i], &has_minus_or_plus))
			return (NULL);
		i++;
	}
	return (*tail);
}
