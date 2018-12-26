/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 12:23:21 by ahavrius          #+#    #+#             */
/*   Updated: 2018/12/02 12:23:22 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"


static int 	check_instractions(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp(line, "sa"))
		swap(*a);
	else if (!ft_strcmp(line, "sb"))
		swap(*b);
	else if (!ft_strcmp(line, "ss"))
	{
		swap(*a);
		swap(*b);
	}
	else if (!ft_strcmp(line, "pa"))
		push(b, a);
	else if (!ft_strcmp(line, "pb"))
		push(a, b);
	else if (!ft_strcmp(line, "ra"))
		rotate(a);
	else if (!ft_strcmp(line, "rb"))
		rotate(b);
	else if (!ft_strcmp(line, "rr"))
	{
		rotate(a);
		rotate(b);
	}
	else if (!ft_strcmp(line, "rra"))
		re_rotate(a);
	else if (!ft_strcmp(line, "rrb"))
		re_rotate(b);
	else if (!ft_strcmp(line, "rrr"))
	{
		re_rotate(a);
		re_rotate(b);
	}
	else
		return (0);
	return (1);
}

static int 	check_stacks(t_stack *a, t_stack *b)
{
	int 		flag;
	t_stack		*head;

	flag  = (b == NULL);
	head = (a) ? a->next : NULL;
	while (a && head != a && flag)
	{
		flag = (head->prev->value <= head->value); //sort by acsel ??
		head = head->next;
	}
	return (flag);
}



int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	int 	flag;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (read_stack(&a, argv, argc) == -1)		
		return (0 * write(1, "Error\n", 6));
	flag = 1;
	while (get_next_line(0, &line) == 1 && flag)
	{
		flag *= check_instractions(&a, &b, line);
		printf("a | ");
		write_stack(a);
		printf("b | ");
		write_stack(b);
	}
	if (!flag)
		write(1, "Error\n", 6);
	else
	{
		flag = check_stacks(a, b);
		if (flag)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	del_all(&a);

	return (0);
}