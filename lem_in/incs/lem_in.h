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

# define MIN_VISITERS 2

# define PATH_TO_VISIT(list) (g_table_visit[(list)->content_size])
# define PATH_LEN(list) (g_table_lens[(list)->content_size])
# define PATH_CROSS(list) (g_table_crossed[(list)->content_size])
# define IF_E(M, ni, N, sum) ((M) > (ni) * (N) - (sum))
# define GET_E_DIV(M, N, sum) (((M) + (sum)) / (N))
# define GET_E_MOD(M, N, sum) (((M) + (sum)) % (N))

typedef struct		s_graph
{
	char			*name;
	int				coord_x;
	int				coord_y;
	t_list			*neighs;
	int				visited;
	int				detected;
	struct s_graph	*from;
}					t_graph;

int					g_num_ants;
t_list				*g_all_nodes;
t_graph				*g_start_node;
t_graph				*g_end_node;

int					g_total_path_len;
int					g_min_effic;
t_list				*g_path_effic;
t_list				**g_table_crossed;
int					*g_table_lens;
char				*g_table_visit;

t_list				*g_input;

int					g_error;

int					g_min_popular;
t_list				*g_all_paths;

t_list				**g_where_go;
int					*g_waiting_time;

void				main_read(void);
t_graph				*graph_new_el(char *name, int x, int y);
int					graph_cmp(void *g1, void *line);
void				graph_del_el(void *el, size_t len);
void				detect_paths(t_graph *where, int is_reverse);
void				define_link(char *name1, char *name2);

void				main_bfs(t_graph *start, t_graph *end);
void				main_efficiency(void);
void				main_rec(void);
void				main_print(void);
int					is_special_case(void);
void				main_special(void);

int					formula_efficience(int ants, int amount, int sum);
int					atoi_correct(const char *str);
void				graph_del_node(void *el, size_t len);

#endif
