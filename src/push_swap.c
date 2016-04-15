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

// int					find_min(t_lst *l)
// {
// 	while (l)
// 	{
// 		if (l->next)
// 		{
// 			if (l->num > l->next->num)
// 				return (0);
// 		}
// 		l = l->next;
// 	}
// 	return (1);
// }

int					main(int ac, char **av)
{
	t_lst	*a;
	t_lst	*b;

	if (ac == 1 || !(a = init_lst(ac, av)) || sorted(a))
		exit(1);
	b = NULL;
	print_a(a);
	print_b(b);
	ft_printf("\n\n");
	sa(a);
	ft_printf("<--");
	print_a(a);
	print_b(b);
	ft_printf("\n\n");
	pb(&b, &a);
	pb(&b, &a);
	pb(&b, &a);
	ft_printf("<--");
	print_a(a);
	print_b(b);
	ft_printf("\n\n");
	rr(a, b);
	ft_printf("<--");
	print_a(a);
	print_b(b);
	ft_printf("\n\n");
	rrr(a, b);
	ft_printf("<--");
	print_a(a);
	print_b(b);
	ft_printf("\n\n");
	sa(a);
	ft_printf("<--");
	print_a(a);
	print_b(b);
	ft_printf("\n\n");
	pa(&a, &b);
	pa(&a, &b);
	pa(&a, &b);
	ft_printf("<--");
	print_a(a);
	print_b(b);
	return (0);
}
