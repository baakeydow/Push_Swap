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

static int			sorted(t_lst *l)
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

int					main(int ac, char **av)
{
	t_lst	*l;

	if (ac == 1 || !(l = init_lst(ac, av)) || sorted(l))
		exit(1);
	// while (l)
	// {
	// 	ft_putnbr(l->num);
	// 	l = l->next;
	// }
	return (0);
}
