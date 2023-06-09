/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 08:59:51 by fahmadia          #+#    #+#             */
/*   Updated: 2023/06/09 09:17:58 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./mylib/ft_printf/ft_printf.h"
#include "./mylib/libft/libft.h"
# include <libc.h>
#include <unistd.h>

typedef struct num_list
{
	int				content;
	struct num_list	*next;
} num_list;

char**	push_swap(int argc, char** argv);
int		validate_args(int argc, char **argv);
char	*check_for_space(char *argv);

#endif