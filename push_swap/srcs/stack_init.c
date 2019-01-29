/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 13:35:44 by ahavrius          #+#    #+#             */
/*   Updated: 2018/12/01 13:35:45 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*init_node(int value, int range)
{
	t_stack		*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	new->range = range;
	new->value = value;
	new->next = new;
	new->prev = new;
	return (new);
}

int				len_stack(t_stack *head)
{
	int		count;
	t_stack	*current;

	if (!head)
		return (0);
	count = 1;
	current = head->next;
	while (current != head)
	{
		count++;
		current = current->next;
	}
	return (count);
}

void			push_to_tail(t_stack **head, int value, int range)
{
	t_stack		*new;

	new = init_node(value, range);
	if (!(*head))
	{
		*head = new;
		return ;
	}
	new->next = *head;
	new->prev = (*head)->prev;
	(*head)->prev->next = new;
	(*head)->prev = new;
}

int				try_push(t_stack *head, int value)
{
	t_stack		*current;

	if (!head)
		return (1);
	current = head->next;
	while (current != head)
	{
		if (current->value == value)
			return (0);
		current = current->next;
	}
	if (head->value == value)
		return (0);
	return (1);
}

void			del_stack(t_stack **head)
{
	t_stack		*current;
	t_stack		*old;

	if (!(*head) || !head)
		return ;
	current = (*head)->next;
	while (current != *head)
	{
		old = current;
		current = current->next;
		free(old);
	}
	free(*head);
	*head = NULL;
}
