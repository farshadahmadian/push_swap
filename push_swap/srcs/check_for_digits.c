/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_digits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:56:18 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/28 16:16:09 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_for_digits(t_node *tail, char	*input, int index)
{
	if (!input[index])
	{
		free_list(tail, delete_node_content);
		throw_an_error();
		return (0);
	}
	while (input[index])
	{
		if (!ft_isdigit(input[index]))
		{
			free_list(tail, delete_node_content);
			throw_an_error();
			return (0);
		}
		index++;
	}
	return (1);
}
