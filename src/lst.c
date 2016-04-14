/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 06:03:23 by bndao             #+#    #+#             */
/*   Updated: 2016/04/14 08:41:56 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst							*init_lst(int ac, char **av)
{
	t_lst		*l;
	int			i;

	i = 2;
	if (ac == 2)
		return (NULL);
	if (!arg_valid(av) || repeated(av))
	{
		write(1, "Error\n", ft_strlen("Error\n"));
		exit(1);
	}
	l = l_new(ft_atoi(av[1]));
	while (av[i])
		push_back_list(l, l_new(ft_atoi(av[i++])));
	return (l);
}

t_lst							*l_new(int n)
{
	t_lst		*node;

	if (!(node = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	node->num = n;
	node->next = NULL;
	return (node);
}

void							push_back_list(t_lst *b_list, t_lst *new)
{
	t_lst		*tmp;

	if (b_list == NULL)
		b_list = new;
	else
	{
		tmp = b_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
