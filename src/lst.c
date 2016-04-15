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
	int			pos;

	i = 2;
	pos = 1;
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
		push_back_list(l, l_new(ft_atoi(av[i++]), ++pos));
	return (l);
}

t_lst							*l_new(int n, int pos)
{
	t_lst		*node;

	if (!(node = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	node->num = n;
	node->pos = pos;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void							lst_add_front(t_lst **l, t_lst *new)
{
	if (*l)
	{
		new->next = (*l);
		(*l)->prev = new;
	}
	*l = new;
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
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
}

void							swap_elem_data(t_lst *num1, t_lst *num2)
{
	t_lst			tmp;

	tmp.num = num1->num;
	num1->num = num2->num;
	num2->num = tmp.num;
	tmp.pos = num1->pos;
	num1->pos = num2->pos;
	num2->pos = tmp.pos;
}
