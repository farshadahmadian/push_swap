/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:49:02 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/28 20:43:13 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	*check_for_space(char *argv)
{
	return (ft_strchr(argv, ' '));
}

static void	*manage_inputs_without_space(t_node **tail, char **copy, int i)
{
	*tail = check_argv(copy[i - 1], tail);
	if (!(*tail))
	{
		free_double_pointer(copy, i - 1);
		return (NULL);
	}
	return (*tail);
}

static void	*manage_inputs_with_space( t_node **tail, char **copy, int i)
{
	int		split_result_length;
	char	**split_result;
	char	delimiter;

	delimiter = ' ';
	split_result = NULL;
	split_result_length = strings_num(copy[i - 1], delimiter);
	split_result = ft_split(copy[i - 1], delimiter);
	*tail = check_split(split_result_length, split_result, tail);
	if (!(*tail))
	{
		free_double_pointer(split_result, split_result_length - 1);
		free_double_pointer(copy, i - 1);
		return (NULL);
	}
	free_double_pointer(split_result, split_result_length - 1);
	return (*tail);
}

static void	*manage_inputs(t_node **tail, char **copy, int i)
{
	if (check_for_space(copy[i - 1]))
	{	
		if (!manage_inputs_with_space(tail, copy, i))
			return (NULL);
	}	
	else
	{
		if (!manage_inputs_without_space(tail, copy, i))
			return (NULL);
	}
	return (*tail);
}

t_node	*validate_args(int argc, char **argv)
{
	int		i;
	t_node	*tail;
	char	**copy;

	i = 1;
	tail = NULL;
	copy = (char **)ft_calloc(argc, sizeof(char *));
	if (!copy)
		return (NULL);
	while (i < argc)
	{
		copy[i - 1] = ft_strdup(argv[i]);
		if (!manage_inputs(&tail, copy, i))
			return (NULL);
		i++;
	}
	if (tail)
		tail = check_for_duplication(tail);
	return (free_double_pointer(copy, i - 2), tail);
}
