/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 17:52:36 by ahavrius          #+#    #+#             */
/*   Updated: 2018/11/03 22:08:53 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_data	*ft_search(t_btree *root, t_data *data, int (*f)(t_data*, t_data*))
{
	while (root && f(root->data, data))
	{
		if (f(root->data, data) > 0)
			root = root->left;
		else
			root = root->right;
	}
	if (!data)
		return (NULL);
	free(data);
	data = NULL;
	if (!root)
		return (NULL);
	return (root->data);
}
