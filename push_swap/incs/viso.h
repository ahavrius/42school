/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viso.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 15:55:19 by ahavrius          #+#    #+#             */
/*   Updated: 2018/12/29 15:55:20 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISO_H
# define VISO_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <mlx.h>
# include <fcntl.h>

# include "get_next_line.h"
# include "push_swap.h"
# define ESC 53
# define ENTER 36
# define SPACE 49
# define COLOR_N 0x82b1ff
# define COLOR_P 0xf4c26b
# define FOOTER 100
# define MARGIN 50
# define STACK_H 5

# define SING(x) (((x) >= 0) ? 1 : -1)
# define ABS(x) (((x) >= 0) ? (x) : -(x))

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
}				t_data;

typedef struct	s_window
{
	int			width;
	int			height;
	int			color;
}				t_window;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_rect
{
	t_point		start;
	t_point		end;
	int			color;
}				t_rect;

typedef struct	s_wind_stack
{
	t_window	*window;
	t_data		*data;
	t_stack		*a;
	t_stack		*b;
}				t_wind_stack;

void			put_rect(t_data *data, t_point start, t_point end, int color);
t_rect			init_rect(t_point x, t_point y, int color);
t_point			init_point(int x_0, int x_1);

void			display(t_data *data, t_window *window, t_stack *a, t_stack *b);
int				main_visual(int argc, char **argv);

void			write_stack(t_stack *a);

#endif
