/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 20:19:38 by omaltsev          #+#    #+#             */
/*   Updated: 2018/11/03 20:23:38 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->key)
		free(data->key);
	if (data->value)
		free(data->value);
	data->key = NULL;
	data->value = NULL;
	free(data);
	data = NULL;
}
