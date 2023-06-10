/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_minus_or_plus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:49:00 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/10 16:10:19 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*check_for_minus_or_plus(char *str)
{
	if (*str == '-' || *str == '+') 
	{
		*str = '\0';
		str++;
		ft_printf("remove minus or plus: %s\n", str);
	}
	return (str);
}