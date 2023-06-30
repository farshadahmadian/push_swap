/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 08:59:15 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/28 19:57:46 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	int		length_a;
	int		i;
	t_lists	lists;

	i = 0;
	lists.a = validate_args(argc, argv);
	if (!lists.a)
		return (0);
	length_a = get_length_of_list(lists.a);
	lists.b = NULL;
	if (!check_if_already_sorted(lists, A))
	{
		free_list(lists.a, delete_node_content);
		free_list(lists.b, delete_node_content);
		return (0);
	}
	sort_three_or_less_numbers(&lists, A);
	sort_four_or_five_numbers(&lists, A);
	sort_six_or_more_numbers(&lists, A);
	free_list(lists.a, delete_node_content);
	free_list(lists.b, delete_node_content);
	return (0);
}
