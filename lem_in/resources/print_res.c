/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:11:53 by ahavrius          #+#    #+#             */
/*   Updated: 2019/02/22 15:11:54 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	sum_size(t_list *lst, void *sum)
{
	*((int *)sum) += PATH_LEN(lst);
}

static void	fill_where_wait(t_list *lst, void *table)
{
	static int	i;
	int			*i_table;
	int			amount;
	int			shift;

	shift = 0;
	i_table = (int *)table;
	amount = i_table[lst->content_size];
	while (shift < amount)
	{
		g_where_go[i + shift] = (t_list *)lst->content;
		g_waiting_time[i + shift] = shift;
		shift++;
	}
	i += amount;
}

static void	init_moving(int n_paths, int sum_paths,
					int ants, int *ants_per_path)
{
	int		i;
	int		div;
	t_list	*path;
	int		m_i;

	i = -1;
	div = GET_E_DIV(g_num_ants, n_paths, sum_paths);
	path = g_path_effic;
	while (path)
	{
		m_i = div - PATH_LEN(path);
		ants_per_path[++i] = m_i;
		ants -= m_i;
		path->content_size = i;
		path = path->next;
	}
	while (ants > 0)
	{
		i = -1;
		while (++i < n_paths)
			ants_per_path[i] += ants / n_paths;
		ants = ants % n_paths;
		n_paths--;
	}
}

void		print_res(void)
{
	int		finished;
	int		i;
	t_graph	*tem_graph;

	finished = 0;
	while (finished != g_num_ants)
	{
		i = -1;
		while (++i < g_num_ants)
			if (g_waiting_time[i] == 0 && g_where_go[i] == NULL)
			{
				ft_printf("L%d-%s ", i + 1, g_end_node->name);
				g_waiting_time[i]--;
				finished++;
			}
			else if (g_waiting_time[i] == 0)
			{
				tem_graph = (t_graph *)(g_where_go[i]->content);
				ft_printf("L%d-%s ", i + 1, tem_graph->name);
				g_where_go[i] = g_where_go[i]->next;
			}
			else
				g_waiting_time[i]--;
		ft_printf("\n");
	}
}

void		main_print(void)
{
	int		sum_paths;
	int		*ants_per_path;
	int		amount_paths;

	if (g_error > 0)
		return ;
	sum_paths = 0;
	amount_paths = ft_lstlen(g_path_effic);
	ants_per_path = (int *)malloc(sizeof(int) * amount_paths);
	g_waiting_time = (int *)malloc(sizeof(int) * g_num_ants);
	g_where_go = (t_list **)malloc(sizeof(t_list *) * g_num_ants);
	ft_lstiter2(g_path_effic, &sum_paths, sum_size);
	init_moving(amount_paths, sum_paths, g_num_ants, ants_per_path);
	ft_lstiter2(g_path_effic, ants_per_path, fill_where_wait);
	print_res();
	free(g_table_lens);
	free(g_table_visit);
	free(g_waiting_time);
	free(g_where_go);
	free(ants_per_path);
	ft_lstdel(&g_path_effic, NULL);
}
