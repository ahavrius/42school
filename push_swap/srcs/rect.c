/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 20:15:45 by ahavrius          #+#    #+#             */
/*   Updated: 2018/12/26 20:15:45 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viso.h"

t_point		init_point(int x_0, int x_1)
{
	t_point		point;

	point.x = x_0;
	point.y = x_1;
	return (point);
}

t_rect		init_rect(t_point x, t_point y, int color)
{
	t_rect	new;

	new.start = x;
	new.end = y;
	new.color = color;
	return (new);
}

void		put_rect(t_data *data, t_point start, t_point end, int color)
{
	int		i;
	int		j;
	t_rect	figure;

	figure = init_rect(start, end, color);
	i = figure.start.x - 1;
	while (++i <= figure.end.x)
	{
		j = figure.start.y - 1;
		while (++j <= figure.end.y)
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, i, j, figure.color);
	}
}
