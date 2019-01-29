/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:04:41 by ahavrius          #+#    #+#             */
/*   Updated: 2019/01/21 16:04:42 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			count_leq_element(t_stack *a, int value, t_func func)
{
	t_stack	*current;
	int		sum;

	if (!a)
		return (0);
	sum = func(a, value);
	current = a->next;
	while (a != current && current->range == a->range)
	{
		sum += func(current, value);
		current = current->next;
	}
	return (sum);
}

int			median_stack(t_stack *a, t_func func)
{
	int		len;
	t_stack	*current;

	if (!a || a->range == FIN)
		return (FIN);
	len = len_stack_while(a, a->range);
	current = a->next;
	if (count_leq_element(a, a->value, func) == MEAN(len))
		return (a->value);
	while (current != a && current->range == a->range)
	{
		if (count_leq_element(a, current->value, func) == MEAN(len))
			return (current->value);
		current = current->next;
	}
	return (a->value);
}

void		find_sort_el(t_stack *a, t_func func)
{
	t_stack	*current;
	int		flag;
	int		len;

	if (!a || a->range == FIN)
		return ;
	flag = 1;
	current = a;
	len = len_stack_till(a, FIN);
	while (current->next != a && current->next->range != FIN)
		current = current->next;
	while (current != a && flag)
	{
		if (count_leq_element(a, current->value, func) == len)
			current->range = FIN;
		else
			flag = 0;
		len--;
		current = current->prev;
	}
	if (flag && count_leq_element(a, current->value, func) == len)
		current->range = FIN;
}

void		fill_range_value(t_stack *a, int value)
{
	t_stack	*current;

	if (!a)
		return ;
	if (a->range == FIN)
		return ;
	current = a->next;
	while (current != a && current->range == a->range)
	{
		current->range = value;
		current = current->next;
	}
	a->range = value;
}

void		tail_to_up(t_stack **a, int value, char c, t_list **output)
{
	if (!a || !*a || value == FIN || len_stack(*a) <= 3 ||
		len_stack_while(*a, value) == len_stack(*a))
		return ;
	while ((*a)->prev->range == value)
		re_rotate_print(a, output, c);
}
