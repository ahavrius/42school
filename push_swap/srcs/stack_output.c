/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 15:19:30 by ahavrius          #+#    #+#             */
/*   Updated: 2019/01/22 15:19:31 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void				swap_print(t_stack *head, t_list **output, char c)
{
	char	*str;

	str = (char *)malloc(3);
	str[0] = 's';
	str[1] = c;
	str[2] = '\0';
	ft_lstadd(output, ft_lstnew(str, 3));
	swap(head);
}

void				push_print(t_stack **a, t_stack **b, t_list **output, char c)
{
	char	*str;

	str = (char *)malloc(3);
	str[0] = 'p';
	str[1] = c;
	str[2] = '\0';
	ft_lstadd(output, ft_lstnew(str, 3));
	push(a, b);
}

void				rotate_print(t_stack **a, t_list **output, char c)
{
	char	*str;

	str = (char *)malloc(3);
	str[0] = 'r';
	str[1] = c;
	str[2] = '\0';
	ft_lstadd(output, ft_lstnew(str, 3));
	rotate(a);
}

void				re_rotate_print(t_stack **a, t_list **output, char c)
{
	char	*str;

	str = (char *)malloc(4);
	str[0] = 'r';
	str[0] = 'r';
	str[2] = c;
	str[3] = '\0';
	ft_lstadd(output, ft_lstnew(str, 4));
	re_rotate(a);
}
