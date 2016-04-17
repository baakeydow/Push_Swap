/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 06:47:23 by bndao             #+#    #+#             */
/*   Updated: 2016/04/17 17:43:31 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void							ra(t_lst *l)
{
	if (!l)
		return ;
	if (l->next)
	{
		swap_loop(l);
		write(1, "ra ", 3);
	}
}

void							rb(t_lst *l)
{
	if (!l)
		return ;
	if (l->next)
	{
		swap_loop(l);
		write(1, "rb ", 3);
	}
}

void							rr(t_lst *a, t_lst *b)
{
	if (!a || !b)
		return ;
	if (a->next && b->next)
	{
		swap_loop(a);
		swap_loop(b);
		write(1, "rr ", 3);
	}
}

void							rra(t_lst *l)
{
	if (!l)
		return ;
	if (l->next)
	{
		last_is_first(l);
		write(1, "rra ", 4);
	}
}

void							rrb(t_lst *l)
{
	if (!l)
		return ;
	if (l->next)
	{
		last_is_first(l);
		write(1, "rrb ", 4);
	}
}
