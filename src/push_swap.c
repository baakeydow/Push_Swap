/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 05:33:00 by bndao             #+#    #+#             */
/*   Updated: 2016/04/14 08:33:32 by bndao            ###   ########.fr       */
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

int					min_to_bottom(t_lst *l, int pos_min, int size)
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

int					max_to_bottom(t_lst *l, int pos_max, int size)
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

static void			dont_care(t_lst **a, t_lst **b)
{
	while (size_list(*a) != 1)
	{
		max_to_bottom(*a, find_max(*a), size_list(*a));
		pb(b, a);
	}
	while (size_list(*b))
		pa(a, b);
}

int					main(int ac, char **av)
{
	t_lst	*a;
	t_lst	*b;

	if (ac == 1 || !(a = init_lst(ac, av)) || sorted(av))
		exit(1);
	b = NULL;
	print_a(a);
	print_b(b);
	ft_printf("\n\n");
	// ft_printf("\n");
	// // min_to_bottom(a, find_min(a), size_list(a));
	// max_to_bottom(a, find_max(a), size_list(a));
	dont_care(&a, &b);
	// // ft_printf("%d\n", a->pos);
	// rra(a);
	// // ft_printf("%d\n", a->pos);
	if (is_sorted(a))
	{
		print_a(a);
		print_b(b);
	}
	return (0);
}
