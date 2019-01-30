/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:05:16 by ahavrius          #+#    #+#             */
/*   Updated: 2019/01/21 16:05:17 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_sort_stack(t_stack *a)
{
	return (len_stack_while(a, FIN) == len_stack(a));
}

int			parce_stack(t_stack **a, t_stack **b, t_func func1, t_list **output)
{
	int		mediana;

	if ((*a)->range == FIN)
		return (FIN);
	mediana = median_stack(*a, func1);
	if (mediana == FIN)
		return (FIN);
	fill_range_value(*a, mediana);
	while (count_leq_element(*a, mediana, func1))
	{
		if (func1(*a, mediana))
			push_print(a, b, output, 'a' + (func1 == leq_stack));
		else
			rotate_print(a, output, 'a' + (func1 == geq_stack));
	}
	return (mediana);
}

void		parce_a(t_stack **a, t_stack **b, t_list **output)
{
	int	mediana;

	if (!is_sort_stack(*a))
	{
		if (len_stack_till(*a, FIN) > 3)
		{
			find_sort_el(*a, leq_stack);
			mediana = parce_stack(a, b, leq_stack, output);
			tail_to_up(a, mediana, 'a', output);
			parce_a(a, b, output);
		}
		else
			sort_tree_elem(a, b, 'a', output);
	}
}

void		sort(t_stack **a, t_stack **b, t_list **output)
{
	int	mediana;

	sort_one_move(a, output);
	sort_two_moves(a, output);
	while (!is_sort_stack(*a) || *b != NULL)
	{
		parce_a(a, b, output);
		if (len_stack(*b) > 3)
		{
			mediana = parce_stack(b, a, geq_stack, output);
			tail_to_up(b, mediana, 'b', output);
		}
		else
		{
			sort_tree_elem(b, a, 'b', output);
			while (*b != NULL)
				push_print(b, a, output, 'a');
		}
	}
}
