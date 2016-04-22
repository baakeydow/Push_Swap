/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   made.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 00:41:23 by bndao             #+#    #+#             */
/*   Updated: 2016/04/22 15:58:10 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					min_to_top(t_lst *l, int pos_min, int size)
{
	if (!l)
		return (0);
	while (pos_min != size)
	{
		if (pos_min == 1)
			rra(l);
		else if (pos_min == 2)
		{
			rra(l);
			rra(l);
		}
		else if (pos_min == size - 1)
			sa(l);
		else
			ra(l);
		pos_min = find_min(l);
		l = l->next;
	}
	return (1);
}

int					max_to_top(t_lst *l, int pos_max, int size)
{
	if (!l)
		return (0);
	while (pos_max != size)
	{
		ra(l);
		pos_max = find_max(l);
		l = l->next;
	}
	return (1);
}

int					is_bigger(int num, t_lst *l)
{
	l = l->next;
	if (!l)
		return (0);
	while (l)
	{
		if (l->num > num)
			return (0);
		l = l->next;
	}
	return (1);
}

int					is_smaller(t_lst *l)
{
	int		num;

	while (l->next)
		l = l->next;
	num = l->num;
	l = l->prev;
	if (num > l->prev->num)
		return (0);
	return (1);
}

int					is_smaller_than(int num, t_lst *l)
{
	l = l->next;
	if (!l)
		return (0);
	while (l)
	{
		if (l->num < num)
			return (0);
		l = l->next;
	}
	return (1);
}
