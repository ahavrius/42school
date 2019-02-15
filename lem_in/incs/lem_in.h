/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:32:51 by ahavrius          #+#    #+#             */
/*   Updated: 2019/02/13 20:32:52 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <limits.h>

typedef struct	s_graph
{
	char		*name;
	int			coord_x;
	int			coord_y;
	t_list		*neighs;
	int			dist;
	char		visited;//0 - not visited,  -1 - direct visit, 1..n - visited how many time
	struct s_graph	*from; //where from come to this node
//	int			ant;
}				t_graph;

t_list			*g_all_nodes;


t_graph			*g_start_node;
t_graph			*g_end_node;

t_linlist		*g_list_head;
t_linlist		*g_list_tail;


int				g_error;

int				g_min_popular; //обновлять каждый цикл
t_list			*g_popular_nodes;
int 			g_num_ants;

void			main_read(void);
t_graph			*graph_new_el(char *name, int x, int y);
int				graph_cmp(void *g1, void *line);
void			graph_del_el(void *el, size_t len);
void			define_link(char *name1, char *name2);

//del
int				atoi_correct(const char *str);

#endif
