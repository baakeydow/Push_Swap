/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 05:33:00 by bndao             #+#    #+#             */
/*   Updated: 2016/04/16 13:12:37 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			print_a(t_lst *a)
{
	ft_putstr("\n\na: ");
	while (a)
	{
		ft_putnbr(a->num);
		ft_putstr(" ");
		a = a->next;
	}
}

static void			print_b(t_lst *b)
{
	ft_putstr("\n\nb: ");
	while (b)
	{
		ft_putnbr(b->num);
		ft_putstr(" ");
		b = b->next;
	}
}

int					min_to_top(t_lst *l, int pos_min, int size)
{
	if (!l)
		return (0);
	while (pos_min != size)
	{
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

int					main(int ac, char **av)
{
	t_lst	*a;
	t_lst	*b;

	if (ac == 1 || !(a = init_lst(ac, av)) || is_sorted(a))
		exit(1);
	b = NULL;
	print_a(a);
	print_b(b);
	ft_printf("\n\n");
	sort_it(&a, &b);
	if (is_sorted(a))
	{
		ft_printf("\n\nsorted !!!");
		print_a(a);
	}
	return (0);
}
