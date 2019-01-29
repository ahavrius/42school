/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 18:49:26 by ahavrius          #+#    #+#             */
/*   Updated: 2018/12/27 20:58:22 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viso.h"

static int	count_abs_max(t_stack *a)
{
	t_stack	*current;
	int		max;

	if (a)
	{
		max = ABS(a->value);
		current = a->next;
		while (current != a)
		{
			max = MAX(ABS(current->value), max);
			current = current->next;
		}
		return (max);
	}
	return (0);
}

static void	display_stack(t_data *data, t_stack *a, float range, int who)
{
	int		i;
	t_stack	*current;

	if (!a)
		return ;
	current = a->prev;
	i = 0;
	while (current != a)
	{
		put_rect(data, init_point(MARGIN + 250 - range * ABS(current->value) +
			500 * who, 1000 + MARGIN - (i + 1) * STACK_H),
			init_point(MARGIN + 250 + range * ABS(current->value) + 500 * who,
			1000 + MARGIN - i * STACK_H),
			(current->value > 0) ? COLOR_P : COLOR_N);
		current = current->prev;
		i++;
	}
	put_rect(data, init_point(MARGIN + 250 - range * ABS(a->value) +
		500 * who, 1000 + MARGIN - (i + 1) * STACK_H),
		init_point(MARGIN + 250 + range * ABS(a->value) + 500 * who,
		1000 + MARGIN - i * STACK_H), (a->value > 0) ? COLOR_P : COLOR_N);
}

void		display(t_data *data, t_window *window, t_stack *a, t_stack *b)
{
	int		max1;
	int		max2;

	mlx_string_put(data->mlx_ptr, data->mlx_win, MARGIN + 250,
		window->height - FOOTER / 2, COLOR_P, "a");
	mlx_string_put(data->mlx_ptr, data->mlx_win, MARGIN + 750,
		window->height - FOOTER / 2, COLOR_P, "b");
	max2 = count_abs_max(b);
	max1 = count_abs_max(a);
	max1 = MAX(max1, max2);
	display_stack(data, a, 250.0 / (max1 + 1), 0);
	display_stack(data, b, 250.0 / (max1 + 1), 1);
}
