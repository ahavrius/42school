/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 17:30:12 by ahavrius          #+#    #+#             */
/*   Updated: 2018/11/03 17:30:27 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_addel(t_btree **root, t_data *data, int (*f)(t_data*, t_data*))
{
	t_btree	*new;
	t_btree	*start;
	t_btree	*current;

	if (!root)
		return ;
	start = *root;
	while (start)
	{
		current = start;
		if (f(start->data, data) > 0)
			start = start->left;
		else
			start = start->right;
	}
	new = ft_newel(data, current);
	if (!*root)
	{
		*root = new;
		return ;
	}
	if (f(current->data, data) > 0)
		current->left = new;
	else
		current->right = new;
}
