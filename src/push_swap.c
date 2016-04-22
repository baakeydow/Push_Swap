/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 05:33:00 by bndao             #+#    #+#             */
/*   Updated: 2016/04/22 15:23:57 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst					*init_lst(int ac, char **av)
{
	t_lst		*l;
	int			i;
	int			pos;

	i = 2;
	pos = ac - 1;
	if (!is_number(av[1]))
	{
		write(1, "Error\n", ft_strlen("Error\n"));
		exit(1);
	}
	if (ac == 2)
		return (NULL);
	if (!args_valid(av) || repeated(av))
	{
		write(1, "Error\n", ft_strlen("Error\n"));
		exit(1);
	}
	l = l_new(ft_atoi(av[1]), pos);
	while (av[i])
		lst_add_front(&l, l_new(ft_atoi(av[i++]), --pos));
	return (l);
}

int						main(int ac, char **av)
{
	t_lst		*a;
	t_lst		*b;

	if (ac == 1 || !(a = init_lst(ac, av)) || is_sorted(a))
		exit(1);
	b = NULL;
	if (size_list(a) == 2)
		sa(a);
	else
		sort_it(&a, &b);
	ft_putchar('\n');
	while (a->next)
		a = a->next;
	while (a)
	{
		ft_putnbr(a->num);
		ft_putchar(' ');
		a = a->prev;
	}
	ft_putchar('\n');
	return (0);
}
