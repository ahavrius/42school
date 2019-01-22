
#include "viso.h"

static int			esc_key(int key, void *param)
{
	char	*line;

	if (key == ESC)
	{
		del_stack(&(((t_wind_stack *)param)->a));
		del_stack(&(((t_wind_stack *)param)->b));
		exit(1);
	}
	if (key == ENTER)
	{
		if (get_next_line(0, &line) <= 0)
			esc_key(ESC, param);
		check_instractions(&((t_wind_stack *)param)->a, &((t_wind_stack *)param)->b, line);
		free(line);
		mlx_clear_window(((t_wind_stack *)param)->data->mlx_ptr, ((t_wind_stack *)param)->data->mlx_win);
		display(((t_wind_stack *)param)->data, ((t_wind_stack *)param)->window, ((t_wind_stack *)param)->a, ((t_wind_stack *)param)->b);
	}
	return (0);
}

static void			init_window(t_data *data, t_window *window)
{
	window->width = 1000 + 2 * MARGIN;
	window->height = 1000 + MARGIN + FOOTER;
	window->color = 0xFFFFFF;
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, window->width,
		window->height, "push_swap");

}

static t_wind_stack	init_all(t_data *data, t_window *window, t_stack *a, t_stack *b)
{
	t_wind_stack	new;

	new.data = data;
	new.window = window;
	new.a = a;
	new.b = b;
	return (new);
}

int					main_visual(int argc, char **argv)
{
	t_data			data;
	t_window		window;
	t_stack			*a;
	t_stack			*b;
	t_wind_stack	all;

	a = NULL;
	b = NULL;
	if (read_stack(&a, argv, argc) == -1)		
		return (0 * write(1, "Error\n", 6));
	init_window(&data, &window);
	all = init_all(&data, &window, a, b);
	display(&data, &window, a, b);
	mlx_hook(data.mlx_win, 2, 5, esc_key, &all);
	mlx_loop(data.mlx_ptr);
	return (0);
}
