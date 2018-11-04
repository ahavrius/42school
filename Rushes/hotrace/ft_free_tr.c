/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 20:24:12 by omaltsev          #+#    #+#             */
/*   Updated: 2018/11/03 20:29:46 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_free_tr(t_btree *root)
{
	if (root)
	{
		ft_free_tr(root->left);
		ft_free_tr(root->right);
		ft_free_data(root->data);
		free(root);
		root = NULL;
	}
}
