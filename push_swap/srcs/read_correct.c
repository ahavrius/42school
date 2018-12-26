/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_correct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 12:24:04 by ahavrius          #+#    #+#             */
/*   Updated: 2018/12/02 12:24:05 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"
#include <limits.h>

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

//delete
void			write_stack(t_stack *a)
{
	t_stack 	*current;

	if (a)
	{
		current = a->next;
		printf("%d ", a->value);
		while (current != a)
		{
			printf("%d ", current->value);
			current = current->next;
		}
	}
	printf("\n");
}		

int				read_stack(t_stack **a, char **arg, int count)
{
	long long	value;
	int			i;

	i = 0;
	while (++i < count)
	{
		value = atoi_correct(arg[i]);
		if (value < INT_MIN || value > INT_MAX || !try_push(*a, value))
			return (-1);
		push_to_tail(a, value);
	}
	return (1);
}
