/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 17:17:12 by omaltsev          #+#    #+#             */
/*   Updated: 2018/11/03 18:01:20 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_data	*ft_newdata(char *key, char *value)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	data->key = key;
	data->value = value;
	return (data);
}

t_btree	*ft_newel(t_data *data, t_btree *root)
{
	t_btree	*newel;

	newel = (t_btree *)malloc(sizeof(t_btree));
	newel->root = root;
	newel->left = NULL;
	newel->right = NULL;
	newel->data = data;
	return (newel);
}
