# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"


typedef struct		s_stack
{
	int				value;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

int					read_stack(t_stack **a, char **arg, int count);
void				push_to_tail(t_stack **head, int value);
void				del_all(t_stack **head);
int 				try_push(t_stack *head, int value);

void				swap(t_stack *head);
//void				swap_all(t_stack *a, t_stack *b);
void				push(t_stack **a, t_stack **b);
void				rotate(t_stack **a);
//void				rotate_all(t_stack *a, t_stack *b);
void				re_rotate(t_stack **a);
//void				re_rotate_all(t_stack *a, t_stack *b);

void				write_stack(t_stack *a);

# endif
