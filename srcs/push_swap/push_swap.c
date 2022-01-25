/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:49:46 by ychibani          #+#    #+#             */
/*   Updated: 2022/01/25 23:24:38 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	_init_stacks_(t_data **a, t_data **b)
{

	*a = malloc(sizeof(t_data));
	*b = malloc(sizeof(t_data));
	if (!a || !b)
		return (_ERROR_);
	(*a)->size = 0;
	(*a)->head = NULL;
	(*a)->tail = NULL;
	(*a)->string = NULL;
	(*b)->size = 0;
	(*b)->head = NULL;
	(*b)->string = NULL;
	(*b)->tail = NULL;
	return (_SUCCESS_);
}

int	main(int ac, char **av)
{
	t_data		*a;
	t_data		*b;

	if (_init_stacks_(&a, &b) == _ERROR_)
		return (ft_putstr_fd("Error\n", 2), 0);
	if (_parse_(ac, av, a) == _ERROR_)
		return (_clean_(a, b), ft_putstr_fd("Error\n", 2));
	if (_init_(a) == _ERROR_)
		return (_clean_(a, b), ft_putstr_fd("Error\n", 2));
	if (_is_sorted_stack_(a))
		return (_clean_(a, b), 0);
	// pb(a, b);
	sa(a);
	_print_data_(a);
	// if (_sorting_algorithm_(a, b))
	// 	return (_clean_(a, b), 0);
	// if (_optimus_algo_(a, b))
	// 	return (_clean(a, b), 0);
	return (_clean_(a, b), 0);
}
