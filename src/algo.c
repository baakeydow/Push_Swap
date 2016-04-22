/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 14:33:16 by bndao             #+#    #+#             */
/*   Updated: 2016/04/22 15:54:30 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void							stupid(t_lst **a, t_lst **b)
{
	while (size_list(*a) != 1 && !is_sorted(*a))
	{
		min_to_top(*a, find_min(*a), size_list(*a));
		pb(b, a);
	}
	while (size_list(*b))
		pa(a, b);
}

int								is_sorted(t_lst *l)
{
	if (!l)
		return (0);
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

void							sort_it(t_lst **a, t_lst **b)
{
	t_lst		*second;

	if (*a)
		second = (*a)->next;
	if (is_inverted(*a) && size_list(*a) == 3)
	{
		sa(*a);
		rra(*a);
	}
	else if (is_sorted(second) && is_bigger((*a)->num, second))
	{
		rra(*a);
		rra(*a);
		sa(*a);
		ra(*a);
		ra(*a);
	}
	else if (is_sorted(second) && is_smaller_than((*a)->num, second))
		rra(*a);
	else if (is_sorted_ex_last(*a) && is_smaller(*a))
		sa(*a);
	else if (is_sorted_ex_last(*a) && last_is_bigger(*a))
		ra(*a);
	else
		stupid(a, b);
}
