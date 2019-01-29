/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 13:36:00 by ahavrius          #+#    #+#             */
/*   Updated: 2018/12/01 13:36:01 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				swap(t_stack *head)
{
	int		current;

	if (head && head->next != head)
	{
		current = head->value;
		head->value = head->next->value;
		head->next->value = current;
		current = head->range;
		head->range = head->next->range;
		head->next->range = current;
	}
}

void				push(t_stack **a, t_stack **b)
{
	t_stack		*cur_a;

	if (!*a)
		return ;
	cur_a = *a;
	push_to_tail(b, (*a)->value, (*a)->range);
	*b = (*b)->prev;
	if (*a == (*a)->next)
		*a = NULL;
	else
	{
		(*a)->next->prev = (*a)->prev;
		(*a)->prev->next = (*a)->next;
		*a = (*a)->next;
	}
	free(cur_a);
}

void				rotate(t_stack **a)
{
	if (*a)
		*a = (*a)->next;
}

void				re_rotate(t_stack **a)
{
	if (*a)
		*a = (*a)->prev;
}
