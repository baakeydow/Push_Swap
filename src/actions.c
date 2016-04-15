/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 23:33:07 by bndao             #+#    #+#             */
/*   Updated: 2016/04/14 23:33:24 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void            sa(t_lst *l)
{
    t_lst   *tmp;

    if (!l)
        return ;
    tmp = l;
    if (l->next)
    {
        while (tmp->next)
            tmp = tmp->next;
        swap_elem_data(tmp->prev, tmp);
        write(1, "sa ", 3);
    }
}

void            sb(t_lst *l)
{
    t_lst   *tmp;

    if (!l)
        return ;
    tmp = l;
    if (l->next)
    {
        while (tmp->next)
            tmp = tmp->next;
        swap_elem_data(tmp->prev, tmp);
        write(1, "sb ", 3);
    }
}

void            pa(t_lst **a, t_lst **b)
{
    t_lst      *tmp;

    if (!*b)
        return ;
    tmp = *b;
    while ((*b)->next)
        (*b) = (*b)->next;
    if (!*a)
        *a = l_new((*b)->num, (*b)->pos);
    else
        push_back_list(*a, l_new((*b)->num, (*b)->pos));
    if (!(*b)->prev)
    {
        *b = NULL;
        free(*b);
    }
    else
    {
        (*b) = (*b)->prev;
        if (*b)
            (*b)->next = NULL;
        *b = tmp;
    }
    write(1, "pa ", 3);
}

void            pb(t_lst **b, t_lst **a)
{
    t_lst   *tmp;

    if (!*a)
        return ;
    tmp = *a;
    while ((*a)->next)
        (*a) = (*a)->next;
    if (!*b)
        *b = l_new((*a)->num, (*a)->pos);
    else
        push_back_list(*b, l_new((*a)->num, (*a)->pos));
    if (!(*a)->prev)
    {
        *a = NULL;
        free(*a);
    }
    else
    {
        (*a) = (*a)->prev;
        if (*a)
            (*a)->next = NULL;
        *a = tmp;
    }
    write(1, "pb ", 3);
}

void							rrr(t_lst *a, t_lst *b)
{
	if (!a || !b)
		return ;
	if (a->next && b->next)
	{
		last_is_first(a);
		last_is_first(b);
		write(1, "rrr ", 4);
	}
}
