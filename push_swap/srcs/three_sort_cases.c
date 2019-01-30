/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort_cases.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:14:10 by ahavrius          #+#    #+#             */
/*   Updated: 2019/01/25 15:14:11 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_021(t_stack **a, t_stack **b, char which, t_list **output)
{
	t_func	func1;

	func1 = (which == 'a') ? leq_stack : geq_stack;
	if (func1(*a, (*a)->next->next->value) &&
		func1((*a)->next->next, (*a)->next->value))
	{
		if (len_stack(*a) <= 3)
		{
			rotate_print(a, output, which);
			swap_print(*a, output, which);
		}
		else
		{
			rotate_print(a, output, which);
			swap_print(*a, output, which);
			re_rotate_print(a, output, which);
		}
	}
}

void	sort_102(t_stack **a, t_stack **b, char which, t_list **output)
{
	t_func	func1;

	func1 = (which == 'a') ? leq_stack : geq_stack;
	if (func1((*a)->next, (*a)->value) && func1(*a, (*a)->next->next->value))
		swap_print(*a, output, which);
}

void	sort_120(t_stack **a, t_stack **b, char which, t_list **output)
{
	t_func	func1;

	func1 = (which == 'a') ? leq_stack : geq_stack;
	if (func1(*a, (*a)->next->value) && func1((*a)->next->next, (*a)->value))
	{
		if (len_stack(*a) <= 3)
			re_rotate_print(a, output, which);
		else
		{
			rotate_print(a, output, which);
			swap_print(*a, output, which);
			re_rotate_print(a, output, which);
			swap_print(*a, output, which);
		}
	}
}

void	sort_201(t_stack **a, t_stack **b, char which, t_list **output)
{
	t_func	func1;

	func1 = (which == 'a') ? leq_stack : geq_stack;
	if (func1((*a)->next, (*a)->next->next->value) &&
		func1((*a)->next, (*a)->value))
	{
		if (len_stack(*a) <= 3)
			rotate_print(a, output, which);
		else
		{
			swap_print(*a, output, which);
			rotate_print(a, output, which);
			swap_print(*a, output, which);
			re_rotate_print(a, output, which);
		}
	}
}

void	sort_210(t_stack **a, t_stack **b, char which, t_list **output)
{
	t_func	func1;

	func1 = (which == 'a') ? leq_stack : geq_stack;
	if (!func1(*a, (*a)->next->value) &&
		func1((*a)->next->next, (*a)->next->value))
	{
		if (len_stack(*a) <= 3)
		{
			swap_print(*a, output, which);
			re_rotate_print(a, output, which);
		}
		else
		{
			rotate_print(a, output, which);
			swap_print(*a, output, which);
			push_print(a, b, output, NOT(which, 'a', 'b'));
			re_rotate_print(a, output, which);
			swap_print(*a, output, which);
			push_print(b, a, output, which);
		}
	}
}
