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
		ft_putstr(" is the ");
		ft_putnbr(a->pos);
		ft_putstr("\n");
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

int					main(int ac, char **av)
{
	t_lst	*a;
	t_lst	*b;

	if (ac == 1 || !(a = init_lst(ac, av)) || sorted(a))
		exit(1);
	b = NULL;
	print_a(a);
	print_b(b);
	ft_printf("\n%d\n", find_min(a));

	return (0);
}
