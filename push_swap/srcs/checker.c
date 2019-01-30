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

#include "push_swap.h"

static int	not_forbiddne_ins(char *line)
{
	return (!ft_strcmp(line, "sa") || !ft_strcmp(line, "ss") ||
		!ft_strcmp(line, "sb") || !ft_strcmp(line, "pa") ||
		!ft_strcmp(line, "pb") || !ft_strcmp(line, "ra") ||
		!ft_strcmp(line, "rr") || !ft_strcmp(line, "rra") ||
		!ft_strcmp(line, "rrr") || !ft_strcmp(line, "rrb") ||
		!ft_strcmp(line, "rb"));
}

int			check_instractions(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp(line, "sa") || !ft_strcmp(line, "ss"))
		swap(*a);
	if (!ft_strcmp(line, "sb") || !ft_strcmp(line, "ss"))
		swap(*b);
	if (!ft_strcmp(line, "pa"))
		push(b, a);
	if (!ft_strcmp(line, "pb"))
		push(a, b);
	if (!ft_strcmp(line, "ra") || !ft_strcmp(line, "rr"))
		rotate(a);
	if (!ft_strcmp(line, "rb") || !ft_strcmp(line, "rr"))
		rotate(b);
	if (!ft_strcmp(line, "rra") || !ft_strcmp(line, "rrr"))
		re_rotate(a);
	if (!ft_strcmp(line, "rrb") || !ft_strcmp(line, "rrr"))
		re_rotate(b);
	free(line);
	return (not_forbiddne_ins(line));
}

int			main_checker(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	int		flag;

	a = NULL;
	b = NULL;
	flag = read_stack(&a, argv, argc);
	while (flag == 1 && get_next_line(0, &line) == 1)
		flag *= check_instractions(&a, &b, line);
	if (flag != 1)
		write(1, "Error\n", 6);
	else
	{
		flag = is_sort_stack_check(a) && (b == NULL);
		if (flag)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	del_stack(&a);
	del_stack(&b);
	return (0);
}
