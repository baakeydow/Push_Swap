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
    if (!l)
        return ;
    if (l->next)
    {
        swap_elem_data(l, l->next);
        write(1, "sa ", 3);
    }
}

void            sb(t_lst *l)
{
    if (!l)
        return ;
    if (l->next)
    {
        swap_elem_data(l, l->next);
        write(1, "sb ", 3);
    }
}

void            pa(t_lst **a, t_lst **b)
{
    if (!*b)
        return ;
    if (!*a)
        *a = l_new((*b)->num);
    else
        push_back_list(*a, l_new((*b)->num));
    *b = (*b)->next;
    write(1, "pa ", 3);
}

void            pb(t_lst **b, t_lst **a)
{
    if (!*a)
        return ;
    if (!*b)
        *b = l_new((*a)->num);
    else
        push_back_list(*b, l_new((*a)->num));
    *a = (*a)->next;
    write(1, "pb ", 3);
}

void            ra(t_lst *l, t_my *b)
{
    if (!l)
        return ;
    if (l->next)
    {
        swap_loop(l, b);
        write(1, "ra ", 3);
    }
}

void            rb(t_lst *l, t_my *b)
{
    if (!l)
        return ;
    if (l->next)
    {
        swap_loop(l, b);
        write(1, "rb ", 3);
    }
}
