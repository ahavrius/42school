/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 16:20:53 by omaltsev          #+#    #+#             */
/*   Updated: 2018/11/03 22:15:49 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef unsigned char	t_byte;
typedef struct		s_data
{
	char *key;
	char *value;
}					t_data;

typedef struct		s_btree
{
	struct s_btree	*root;
	struct s_btree	*left;
	struct s_btree	*right;
	struct s_data	*data;
}					t_btree;

typedef struct		s_list
{
	t_data			*data;
	char			*key;
	struct s_list	*next;
}					t_list;

t_list				*g_head;
t_list				*g_tail;

void				ft_lstpush(t_data *data, char *key);
t_list				*ft_lstnext(t_list *head);
void				ft_printres(t_data *data, char *key);
void				ft_free_data(t_data *data);
void				ft_free_tr(t_btree *root);
t_data				*ft_newdata(char *key, char *value);
t_btree				*ft_newel(t_data *data, t_btree *root);
void				ft_addel(t_btree **root, t_data *data,
						int (*f)(t_data*, t_data*));
t_data				*ft_search(t_btree *root, t_data *data,
						int (*f)(t_data*, t_data*));
int					ft_datacmp(t_data *data1, t_data *data2);

#endif
