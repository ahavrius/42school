/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 13:02:33 by ahavrius          #+#    #+#             */
/*   Updated: 2019/01/28 13:02:33 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		roll_up_del_2(t_list *elem)
{
	if ((!ft_strcmp(elem->content, "ra\n") &&
		!ft_strcmp(elem->next->content, "rra\n")) ||
		(!ft_strcmp(elem->content, "rra\n") &&
		!ft_strcmp(elem->next->content, "ra\n")) ||
		(!ft_strcmp(elem->content, "rb\n") &&
		!ft_strcmp(elem->next->content, "rrb\n")) ||
		(!ft_strcmp(elem->content, "rrb\n") &&
		!ft_strcmp(elem->next->content, "rb\n")) ||
		(!ft_strcmp(elem->content, "pa\n") &&
		!ft_strcmp(elem->next->content, "pb\n")) ||
		(!ft_strcmp(elem->content, "pb\n") &&
		!ft_strcmp(elem->next->content, "pa\n")) ||
		(!ft_strcmp(elem->content, "sa\n") &&
		!ft_strcmp(elem->next->content, "sa\n")) ||
		(!ft_strcmp(elem->content, "sb\n") &&
		!ft_strcmp(elem->next->content, "sb\n")))
	{
		ft_lstdelnext(elem, del_output);
		((char *)elem->content)[0] = '*';
		elem->content_size = 1;
	}
}

static void		roll_up_del_1(t_list *elem)
{
	char	c;
	t_list	*del;

	c = '\0';
	if ((!ft_strcmp(elem->content, "sa\n") &&
		!ft_strcmp(elem->next->content, "sb\n")) ||
		(!ft_strcmp(elem->content, "sb\n") &&
		!ft_strcmp(elem->next->content, "sa\n")))
		c = 's';
	else if ((!ft_strcmp(elem->content, "ra\n") &&
		!ft_strcmp(elem->next->content, "rb\n")) ||
		(!ft_strcmp(elem->content, "rb\n") &&
		!ft_strcmp(elem->next->content, "ra\n")))
		c = 'r';
	else if ((!ft_strcmp(elem->content, "rra\n") &&
		!ft_strcmp(elem->next->content, "rrb\n")) ||
		(!ft_strcmp(elem->content, "rrb\n") &&
		!ft_strcmp(elem->next->content, "rra\n")))
		c = 'R';
	if (c != '\0')
	{
		((char *)elem->content)[1 + (c == 'R')] = (c == 'R') ? 'r' : c;
		ft_lstdelnext(elem, del_output);
	}
}

static void		roll_up(t_list *elem)
{
	if (!elem || elem->next == NULL)
		return ;
	if (elem->next->content_size < 2)
		ft_lstdelnext(elem, del_output);
	if (elem->next == NULL)
		return ;
	roll_up_del_1(elem);
	roll_up_del_2(elem);
}

static void		print_el(t_list *elem)
{
	if (elem != NULL)
		write(1, elem->content, elem->content_size - 1);
}

void			print_output(t_list *output)
{
	int	i;
	int	j;

	i = ft_lstlen(output);
	j = i - 1;
	while (i != j)
	{
		i = j;
		ft_lstiter(output, roll_up);
		j = ft_lstlen(output);
	}
	ft_lstiter(output, print_el);
}
