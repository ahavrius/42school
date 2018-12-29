/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_visual.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 10:29:00 by ahavrius          #+#    #+#             */
/*   Updated: 2018/12/27 10:29:01 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual_filler.h"

void	skip(int times)
{
	char	*line;

	while (--times >= 0)
	{
		get_next_line(0, &line);
		free(line);
	}
}

int		esc_key(int key, void *param)
{
	if (key == ESC)
		exit(1);
	if (!g_terminate)
		get_and_print(param);
	if (g_terminate)
		mlx_string_put(((t_data *)param)->mlx_ptr, ((t_data *)param)->mlx_win,
			485 + MARGIN, 1000 + MARGIN, 0xFFFFFF, "FIN");
	return (0);
}

int		main(void)
{
	t_data		data;
	t_window	window;

	window.width = 1000 + 2 * MARGIN;
	window.height = 1000 + MARGIN + FOOTER;
	window.color = 0xFFFFFF;
	g_player1 = NULL;
	g_player2 = NULL;
	data.mlx_ptr = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx_ptr, window.width, window.height,
		"filler buttle");
	mlx_hook(data.mlx_win, 2, 5, esc_key, &data);
	mlx_loop(data.mlx_ptr);
	free(g_player1);
	free(g_player2);
	return (1);
}
