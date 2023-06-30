/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_minus_or_plus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:49:00 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/28 16:20:14 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_for_minus_or_plus(char *str, int *has_minus_or_plus)
{
	if (*str == '-' || *str == '+')
		*has_minus_or_plus = 1;
	else
		*has_minus_or_plus = 0;
}
