/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_digits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 11:02:09 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/11 17:28:41 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_for_digits(int length, char **split_result, char *argv, int flag, int *has_minus_or_plus)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (flag == 1)
	{
		check_for_minus_or_plus(argv, has_minus_or_plus);
		ft_printf("argv[i] = %s\n", argv);
		if (*has_minus_or_plus)
			i = 1;
		while (argv[i])
		{
			if (!ft_isdigit(argv[i++]))
				return (0);
		}
		return (1);
	}
	while (i < length) 
	{
		check_for_minus_or_plus(split_result[i], has_minus_or_plus);
		ft_printf("from check_for_digits: split_result[i] = %s\n", split_result[i]);
		while (split_result[i][j]) 
		{
			if (*has_minus_or_plus) 
				j = 1;
			if (!ft_isdigit(split_result[i][j++]))
				return (0);
		}
		i++;
		j = 0;
	}
	return (1);
}
