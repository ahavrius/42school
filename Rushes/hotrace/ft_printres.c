/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printres.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 19:42:43 by omaltsev          #+#    #+#             */
/*   Updated: 2018/11/03 22:07:43 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i++], 1);
	}
}

void		ft_printres(t_data *data, char *key)
{
	if (!data)
	{
		ft_putstr(key);
		ft_putstr(": Not found.");
	}
	else
		ft_putstr(data->value);
	ft_putstr("\n");
}
