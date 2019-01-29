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

void		swap_print(t_stack *head, t_list **output, char c)
{
	char	*str;

	str = (char *)malloc(4);
	str[0] = 's';
	str[1] = c;
	str[2] = '\n';
	str[3] = '\0';
	ft_lstadd(output, ft_lstnew(str, 4));
	swap(head);
	free(str);
}

void		push_print(t_stack **a, t_stack **b, t_list **output, char c)
{
	char	*str;

	str = (char *)malloc(4);
	str[0] = 'p';
	str[1] = c;
	str[2] = '\n';
	str[3] = '\0';
	ft_lstadd(output, ft_lstnew(str, 4));
	push(a, b);
	free(str);
}

void		rotate_print(t_stack **a, t_list **output, char c)
{
	char	*str;

	str = (char *)malloc(4);
	str[0] = 'r';
	str[1] = c;
	str[2] = '\n';
	str[3] = '\0';
	ft_lstadd(output, ft_lstnew(str, 4));
	rotate(a);
	free(str);
}

void		re_rotate_print(t_stack **a, t_list **output, char c)
{
	char	*str;

	str = (char *)malloc(5);
	str[0] = 'r';
	str[1] = 'r';
	str[2] = c;
	str[3] = '\n';
	str[4] = '\0';
	ft_lstadd(output, ft_lstnew(str, 5));
	re_rotate(a);
	free(str);
}
