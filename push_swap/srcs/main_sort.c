/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:48:46 by ahavrius          #+#    #+#             */
/*   Updated: 2019/01/08 12:48:46 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		leq_stack(t_stack *a, int value)// <=
{
	if (!a)
		return (0);
	return (a->value <= value);
}

int		geq_stack(t_stack *a, int value)// >=
{
	if (!a)
		return (0);
	return (a->value >= value);
}

int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (read_stack(&a, argv, argc) == -1)		
		return (0 * write(1, "Error\n", 6));
	sort(&a, &b);

	//parce_stack(&a, &b, &leq_stack);
	//write_stack(a);
	//write_stack(b);
	del_stack(&a);
	del_stack(&b);
	return (0);
}