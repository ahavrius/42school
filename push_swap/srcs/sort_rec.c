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

static	int	is_sort_stack(t_stack *a)
{
	return (len_stack_till(a, FIN) == 0);
}

void	sort_tree_elem(t_stack **a,t_func func1, char which)

{
	find_sort_el(*a, func1);
	if (!a || !*a || is_sort_stack(*a))
		return ;
	if (!func1(*a, (*a)->next->value) && *a == (*a)->next->next) //for two els
	{
		swap(*a);
		printf("s%c\n", which);
	}/*
	else if (func1(*a, (*a)->next->next->value) && func1((*a)->next->next, (*a)->next->value)) //021
	{
		rotate(a);
		swap(*a);
		printf("r%c\ns%c\n", which, which);
	}
	else if (func1((*a)->next, (*a)->value) && func1(*a, (*a)->next->next->value)) //102
	{
		swap(*a);
		printf("s%c\n", which);
	}
	else if (func1(*a, (*a)->next->value) && func1((*a)->next->next, (*a)->value)) //120
	{
		re_rotate(a);
		printf("rr%c\n", which);
	}
	else if (func1((*a)->next, (*a)->next->next->value) && func1((*a)->next, (*a)->value)) //201
	{
		rotate(a);
		printf("r%c\n", which);
	}
	else if (!func1(*a, (*a)->next->value) && func1((*a)->next->next, (*a)->next->value)) // 210
	{
		re_rotate(a);
		re_rotate(a);
		printf("rr%c\nrr%c", which, which);
	}*/
//fill FIN
	fill_range_value(*a, FIN);
}


int		parce_stack(t_stack **a, t_stack **b, t_func func1) //char 'a'/'b'
{
	int		mediana;

	find_sort_el(*a, func1);
	if ((*a)->range == FIN)
		return (FIN);
	mediana = median_stack(*a, func1);
	if (mediana == FIN)
		return (FIN);
	fill_range_value(*a, mediana);
	while (count_leq_element(*a, mediana, func1))
	{
		if (func1(*a, mediana))
		{
			push(a, b);
			printf("p%c\n", 'a' + (func1 == leq_stack)); //'b' for a
		}
		else
		{
			rotate(a);
			printf("r%c\n", 'a' + (func1 == geq_stack)); //'a' for a
		}
	}
	return (mediana);
}

void	parce_a(t_stack **a, t_stack **b)
{
	int	mediana;

	if (!is_sort_stack(*a))
	{
		if (len_stack_till(*a, FIN) > 2)
		{
			mediana = parce_stack(a, b, leq_stack);
			parce_a(a, b);
			tail_to_up(a, mediana, "rra");
		}
		else
			sort_tree_elem(a, leq_stack, 'a');
	}
}


void	sort(t_stack **a, t_stack **b)
{
	int	mediana;

	while (!is_sort_stack(*a) || *b != NULL)
	{
		parce_a(a, b);
		if (len_stack_till(*b, FIN) > 2)
		{
			mediana = parce_stack(b, a, geq_stack);
			tail_to_up(b, mediana, "rrb");
		}
		else //if or while
			if (*b != NULL)
		{
			push(b, a);
			printf("pa\n");
		}
	}
}