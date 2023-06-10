/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 08:59:51 by fahmadia          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/06/10 12:35:35 by fahmadia         ###   ########.fr       */
=======
/*   Updated: 2023/06/09 09:17:58 by fahmadia         ###   ########.fr       */
>>>>>>> e7668c073e565f2fdfcd9cf81439d717eb7c7fe4
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
<<<<<<< HEAD
int	check_for_digits(int length, char **split_result, char *argv, int flag);
=======
>>>>>>> e7668c073e565f2fdfcd9cf81439d717eb7c7fe4

#endif