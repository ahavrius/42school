/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:02:00 by ahavrius          #+#    #+#             */
/*   Updated: 2019/01/29 15:02:04 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

# define MAX(x, y) (((x) > (y)) ? (x) : (y))
# define MIN(x, y) (((x) < (y)) ? (x) : (y))
# define NOT(x, y, z) (((x) == (y)) ? (z) : (y))
# define FIN INT_MIN
# define MEAN(x) ((x) / 2 + ((x) % 2))

typedef struct		s_stack
{
	int				value;
	struct s_stack	*prev;
	struct s_stack	*next;
	int				range;
}					t_stack;

typedef	int			(*t_func)(t_stack *, int);

int					read_stack(t_stack **a, char **arg, int count);
void				push_to_tail(t_stack **head, int value, int range);
void				del_stack(t_stack **head);
int					try_push(t_stack *head, int value);

void				swap(t_stack *head);
void				push(t_stack **a, t_stack **b);
void				rotate(t_stack **a);
void				re_rotate(t_stack **a);

int					check_instractions(t_stack **a, t_stack **b, char *line);

int					main_checker(int argc, char **argv);
int					main_sort(int argc, char **argv);

void				swap_print(t_stack *head, t_list **output, char c);
void				push_print(t_stack **a, t_stack **b,
								t_list **output, char c);
void				rotate_print(t_stack **a, t_list **output, char c);
void				re_rotate_print(t_stack **a, t_list **output, char c);
void				print_output(t_list *output);

int					len_stack_till(t_stack *head, int range);
int					len_stack_while(t_stack *head, int range);
int					len_stack(t_stack *head);

void				sort(t_stack **a, t_stack **b, t_list **output);
void				sort_tree_elem(t_stack **a, t_stack **b,
									char which, t_list **output);
int					is_sort_stack_check(t_stack *a);
int					is_sort_stack(t_stack *a);

void				sort_021(t_stack **a, t_stack **b,
								char which, t_list **output);
void				sort_102(t_stack **a, t_stack **b,
								char which, t_list **output);
void				sort_120(t_stack **a, t_stack **b,
								char which, t_list **output);
void				sort_201(t_stack **a, t_stack **b,
								char which, t_list **output);
void				sort_210(t_stack **a, t_stack **b,
								char which, t_list **output);
void				sort_one_move(t_stack **a, t_list **output);
void				sort_two_moves(t_stack **a, t_list **output);

int					median_stack(t_stack *a, t_func func);
void				find_sort_el(t_stack *a, t_func func);
void				fill_range_value(t_stack *a, int value);
int					count_leq_element(t_stack *a, int value, t_func func);
void				tail_to_up(t_stack **a, int	value,
								char c, t_list **output);

int					leq_stack(t_stack *a, int value);
int					geq_stack(t_stack *a, int value);

void				del_output(void *line, size_t len);
void				read_with_args(char *str, int (*f)(int, char **));

#endif
