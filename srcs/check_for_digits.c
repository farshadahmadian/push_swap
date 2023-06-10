/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_digits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 11:02:09 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/10 16:10:05 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_for_digits(int length, char **split_result, char *argv, int flag)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (flag == 1)
	{
		argv = check_for_minus_or_plus(argv);
		ft_printf("argv[i] = %s\n", argv);
		while (argv[i])
		{
			if (!ft_isdigit(argv[i++]))
				return (0);
		}
		return (1);
	}
	while (i < length)
	{
		split_result[i] = check_for_minus_or_plus(split_result[i]);
			 ft_printf("split_result[i] = %s\n", split_result[i]);
		while (split_result[i][j])
		{
			if (!ft_isdigit(split_result[i][j++]))
				return (0);
		}
		i++;
		j = 0;
	}
	return (1);
}
