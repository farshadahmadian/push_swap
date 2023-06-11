/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_minus_or_plus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:49:00 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/11 17:28:47 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_for_minus_or_plus(char *str, int* has_minus_or_plus)
{
	if (*str == '-' || *str == '+') 
	{
		*has_minus_or_plus = 1;
		ft_printf("has_minus_or_plus: %d\n", *has_minus_or_plus);
	}
	else
		*has_minus_or_plus = 0;
}
