/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:30:17 by ahavrius          #+#    #+#             */
/*   Updated: 2019/01/29 18:30:19 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		leq_stack(t_stack *a, int value)
{
	if (!a)
		return (0);
	return (a->value <= value);
}

int		geq_stack(t_stack *a, int value)
{
	if (!a)
		return (0);
	return (a->value >= value);
}

void	del_output(void *line, size_t len)
{
	free(line);
	line = NULL;
}

int		main_sort(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_list	*output;

	a = NULL;
	b = NULL;
	output = NULL;
	if (read_stack(&a, argv, argc) == -1)
		return (0 * write(1, "Error\n", 6));
	sort(&a, &b, &output);
	output = ft_lst_reverse(output);
	print_output(output);
	ft_lstdel(&output, del_output);
	del_stack(&a);
	del_stack(&b);
	return (0);
}
