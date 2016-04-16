/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 07:07:09 by bndao             #+#    #+#             */
/*   Updated: 2016/04/16 12:25:38 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int								sorted(char **av)
{
	t_lst		*l;
	int			i;
	int			pos;

	i = 2;
	pos = 1;
	l = l_new(ft_atoi(av[1]), pos);
	while (av[i])
		lst_add_front(&l, l_new(ft_atoi(av[i++]), ++pos));
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

int								size_list(t_lst *l)
{
	return (l) ? (size_list(l->next) + 1) : (0);
}

t_lst							*last_is_first(t_lst *start)
{
	t_lst		*nextone;
	t_lst		*begin;

	begin = start;
	nextone = start->next;
	while (start && start->next != NULL)
	{
		swap_elem_data(start, nextone);
		start = start->next;
		nextone = nextone->next;
	}
	nextone = begin;
	start = begin;
	return (start);
}

t_lst							*swap_loop(t_lst *start)
{
	t_lst		*prevone;
	t_lst		*begin;
	t_lst		*end;
	t_lst		*tmp;

	begin = start;
	tmp = start;
	while (tmp->next)
		tmp = tmp->next;
	end = tmp;
	prevone = end->prev;
	while (end && end->prev != NULL)
	{
		swap_elem_data(end, prevone);
		end = end->prev;
		prevone = prevone->prev;
	}
	prevone = begin;
	end = begin;
	return (end);
}

int					find_min(t_lst *l)
{
	int		pos;
	int		last;

	if (!l)
		return (0);
	pos = l->pos;
	last = l->num;
	while (l)
	{
		if (last > l->num)
		{
			pos = l->pos;
			last = l->num;
		}
		l = l->next;
	}
	return (pos);
}

int					find_max(t_lst *l)
{
	int		pos;
	int		last;

	if (!l)
		return (0);
	pos = l->pos;
	last = l->num;
	while (l)
	{
		if (last < l->num)
		{
			pos = l->pos;
			last = l->num;
		}
		l = l->next;
	}
	return (pos);
}
