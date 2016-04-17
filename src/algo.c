/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 14:33:16 by bndao             #+#    #+#             */
/*   Updated: 2016/04/17 14:33:27 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				stupid(t_lst **a, t_lst **b)
{
	while (size_list(*a) != 1)
	{
		min_to_top(*a, find_min(*a), size_list(*a));
		pb(b, a);
	}
	while (size_list(*b))
		pa(a, b);
}

int								is_sorted(t_lst *l)
{
	while (l)
	{
		if (l->next)
		{
			if (l->num < l->next->num)
				return (0);
		}
		l = l->next;
	}
	return (1);
}

int								is_sorted_ex_last(t_lst *l)
{
    if (!l)
        return (0);
	while (l->next)
	{
		if (l->next->next)
		{
			if (l->num < l->next->num)
				return (0);
		}
		l = l->next;
	}
	return (1);
}

int								is_inverted(t_lst *l)
{
	while (l)
	{
		if (l->next)
		{
			if (l->num > l->next->num)
				return (0);
		}
		l = l->next;
	}
	return (1);
}

static int                      just_swap(t_lst *a)
{
    sa(a);
    if (is_sorted(a))
        return (1);
    return (0);
}

void                            sort_it(t_lst **a, t_lst **b)
{
    t_lst       *tmp;

    tmp = (*a)->next;
    if (is_inverted(*a) && size_list(*a) == 3)
	{
		sa(*a);
		rra(*a);
	}
    else if (is_sorted(tmp->next))
    {
        rra(*a);
        rra(*a);
        sa(*a);
        ra(*a);
        ra(*a);
    }
    else if (is_sorted_ex_last(*a))
        ra(*a);
    else if (just_swap(*a))
        ;
    else
        stupid(a, b);
}
