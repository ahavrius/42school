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

static int	count_min_max(t_stack *a, int *min_current, int *max_current, int flag)
{
	t_stack	*current;
	int 	max;
	int 	min;

	if (!a)
		return (1);
	max = a->value;
	min = a->value;
	current = a->next;
	while (current != a)
	{
		max = (current->value > max) ? current->value : max;
		min = (current->value < min) ? current->value : min;
		current = current->next;
	}
	*max_current = (flag || max > *max_current) ? max : *max_current;
	*min_current = (flag || min < *min_current) ? min : *min_current;
	return (0);
}

static void	display_stack(t_data *data, t_stack *a, float range, int min, int who)
{
	int		i;
	t_stack	*current;

	if (!a)
		return ;
	current = a->prev;
	i = 0;
	while (current != a)
	{
		put_rect(data, init_point(MARGIN + 250 - range * (current->value - min)+ 500 * who,
			1000 + MARGIN  - (i + 1) * STACK_H),
			init_point(MARGIN + 250 + range * (current->value - min) + 500 * who,
			1000 + MARGIN  - i * STACK_H), COLOR_A * !who + COLOR_B * who);
		current = current->prev;
		i++;
	}//for a
	put_rect(data, init_point(MARGIN + 250 - range * (a->value - min) + 500 * who,
		1000 + MARGIN  - (i + 1) * STACK_H),
		init_point(MARGIN + 250 + range * (a->value - min) + 500 * who,
		1000 + MARGIN  - i * STACK_H), COLOR_A * !who + COLOR_B * who);
}

void		display(t_data *data, t_window *window, t_stack *a, t_stack *b)
{
	int		max;
	int		min;

	mlx_string_put(data->mlx_ptr, data->mlx_win, MARGIN + 250,
		window->height - FOOTER / 2, COLOR_A, "a");
	mlx_string_put(data->mlx_ptr, data->mlx_win, MARGIN + 750,
		window->height - FOOTER / 2, COLOR_B, "b");
	count_min_max(b, &min, &max, count_min_max(a, &min, &max, 1));
	display_stack(data, a, 250.0 / (max - min + 1), min, 0);
	display_stack(data, b, 250.0 / (max - min + 1), min, 1);
}
