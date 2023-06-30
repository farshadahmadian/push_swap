/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_double_pointer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 08:45:29 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/28 18:39:03 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_double_pointer(char **ptr, int i)
{
	if (!ptr)
		return ;
	while (i >= 0)
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i--;
	}
	free (ptr);
	ptr = NULL;
}
