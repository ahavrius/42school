/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:15:38 by ahavrius          #+#    #+#             */
/*   Updated: 2019/01/28 18:15:39 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter2(t_list **lst, void (*f)(t_list **elem))
{
	t_list	*current;

	if (!f || !lst)
		return ;
	current = *lst;
	while (*lst)
	{
		f(lst);
		if (*lst)
			*lst = (*lst)->next;
	}
	*lst = current;
}
