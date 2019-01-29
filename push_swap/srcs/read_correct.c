/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_correct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 12:24:04 by ahavrius          #+#    #+#             */
/*   Updated: 2019/01/23 20:51:31 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					is_sort_stack_check(t_stack *a)
{
	int		flag;
	t_stack	*head;

	flag = 1;
	head = (a) ? a->next : NULL;
	while (a && head != a && flag)
	{
		flag = (head->prev->value <= head->value);
		head = head->next;
	}
	return (flag);
}

static long long	atoi_correct(const char *str)
{
	long long	res;
	int			sign;

	if (str == NULL)
		return ((long long)INT_MAX + 1);
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	res = 0;
	while (*str && *str >= '0' && *str <= '9')
		res = 10 * res - '0' + *str++;
	if (!*str)
		return (res * sign);
	return ((long long)INT_MAX + 1);
}

int					read_stack(t_stack **a, char **arg, int count)
{
	long long	value;
	int			i;

	i = -1;
	while (++i < count)
	{
		value = atoi_correct(arg[i]);
		if (value < INT_MIN || value > INT_MAX || !try_push(*a, value))
			return (-1);
		push_to_tail(a, value, 0);
	}
	return (1);
}
