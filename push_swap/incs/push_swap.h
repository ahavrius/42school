# ifndef PUSH_SWAP_H
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
# define MEAN(x) ((x) / 2 + 1 * ((x) % 2))

typedef struct		s_stack
{
	int				value;
	struct s_stack	*prev;
	struct s_stack	*next;
	int				range;
}					t_stack;

typedef				int (*t_func)(t_stack *, int); 


int					read_stack(t_stack **a, char **arg, int count);
void				push_to_tail(t_stack **head, int value, int range);
void				del_stack(t_stack **head);
int 				try_push(t_stack *head, int value);

void				swap(t_stack *head);
//void				swap_all(t_stack *a, t_stack *b);
void				push(t_stack **a, t_stack **b);
void				rotate(t_stack **a);
//void				rotate_all(t_stack *a, t_stack *b);
void				re_rotate(t_stack **a);
//void				re_rotate_all(t_stack *a, t_stack *b);

int					check_instractions(t_stack **a, t_stack **b, char *line);

int					main_checker(int argc, char **argv);

//change - unite - think more ....
int					len_stack_till(t_stack *head, int range);
int				len_stack_while(t_stack *head, int range);
int				len_stack(t_stack *head);


//change
int	parce_stack(t_stack **a, t_stack **b, t_func func1);
void	parce_a(t_stack **a, t_stack **b);
void	sort(t_stack **a, t_stack **b);



int			median_stack(t_stack *a, t_func func);
void		find_sort_el(t_stack *a, t_func func);
void	fill_range_value(t_stack *a, int value);
int			count_leq_element(t_stack *a, int value, t_func func);

void	tail_to_up(t_stack **a, int	value, char *str);

//func
int		leq_stack(t_stack *a, int value);
int		geq_stack(t_stack *a, int value);


//del
//void			write_stack(t_stack *a);

# endif
