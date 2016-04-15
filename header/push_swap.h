/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 05:34:17 by bndao             #+#    #+#             */
/*   Updated: 2016/04/14 08:45:05 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct		s_my
{
	struct s_lst	*begin;
}					t_my;

typedef struct		s_lst
{
	int				num;
	struct s_lst	*next;
}					t_lst;

void				sa(t_lst *l);
void				sb(t_lst *l);
void				pa(t_lst **a, t_lst **b);
void				pb(t_lst **b, t_lst **a);
void				ra(t_lst *l, t_my *b);
void				rb(t_lst *l, t_my *b);
void				rra(t_lst **l);
int					sorted(t_lst *l);

t_lst				*l_new(int n);
t_lst				*init_lst(int ac, char **av);
t_my				*init_begin(t_lst *l);
t_lst				*swap_loop(t_lst *start, t_my *mylist);
void				push_back_list(t_lst *b_list, t_lst *new);
void				lst_add_front(t_lst **l, t_lst *new);
void				swap_elem_data(t_lst *num1, t_lst *num2);

int					is_number(char *s);
int					arg_valid(char **av);
int					repeated(char **av);

#endif
