/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 08:59:15 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/10 16:10:24 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	int i;
	
	i = 0;
	validate_args(argc, argv);
	while (i < argc)
	{
		printf("***** %s\n", argv[i]);
		i++;
	}
	
	return (0);
}