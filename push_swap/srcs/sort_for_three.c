/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 19:07:40 by ahavrius          #+#    #+#             */
/*   Updated: 2019/01/24 19:07:41 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_one_move(t_stack **a, t_list **output)
{
	swap_print(*a, output, 'a');
	if (!is_sort_stack_check(*a))
		swap_print(*a, output, 'a');
	rotate_print(a, output, 'a');
	if (!is_sort_stack_check(*a))
		re_rotate_print(a, output, 'a');
	re_rotate_print(a, output, 'a');
	if (!is_sort_stack_check(*a))
		rotate_print(a, output, 'a');
	swap_print(*a, output, 'a');
	rotate_print(a, output, 'a');
	if (!is_sort_stack_check(*a))
	{
		re_rotate_print(a, output, 'a');
		swap_print(*a, output, 'a');
	}
}

void	sort_two_moves(t_stack **a, t_list **output)
{
	swap_print(*a, output, 'a');
	re_rotate_print(a, output, 'a');
	if (!is_sort_stack_check(*a))
	{
		rotate_print(a, output, 'a');
		swap_print(*a, output, 'a');
	}
	rotate_print(a, output, 'a');
	swap_print(*a, output, 'a');
	if (!is_sort_stack_check(*a))
	{
		swap_print(*a, output, 'a');
		re_rotate_print(a, output, 'a');
	}
	re_rotate_print(a, output, 'a');
	swap_print(*a, output, 'a');
	if (!is_sort_stack_check(*a))
	{
		swap_print(*a, output, 'a');
		rotate_print(a, output, 'a');
	}
}

int		len_stack_till(t_stack *head, int range)
{
	int		count;
	t_stack	*current;

	if (!head || head->range == range)
		return (0);
	count = 1;
	current = head->next;
	while (current != head && current->range != range)
	{
		count++;
		current = current->next;
	}
	return (count);
}

int		len_stack_while(t_stack *head, int range)
{
	int		count;
	t_stack	*current;

	if (!head || head->range != range)
		return (0);
	count = 1;
	current = head->next;
	while (current != head && current->range == range)
	{
		count++;
		current = current->next;
	}
	return (count);
}

void	sort_tree_elem(t_stack **a, t_stack **b, char which, t_list **output)
{
	t_func	func1;

	func1 = (which == 'a') ? leq_stack : geq_stack;
	find_sort_el(*a, func1);
	if (!a || !*a || (is_sort_stack(*a)))
		return ;
	if (len_stack_while(*a, FIN) == 2)
		swap_print(*a, output, which);
	sort_021(a, b, which, output);
	sort_102(a, b, which, output);
	sort_120(a, b, which, output);
	sort_201(a, b, which, output);
	sort_210(a, b, which, output);
	fill_range_value(*a, FIN);
}
