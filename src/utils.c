/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 07:07:09 by bndao             #+#    #+#             */
/*   Updated: 2016/04/14 08:54:34 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int								sorted(t_lst *l)
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

int								size_list(t_lst *l)
{
	return (l) ? (size_list(l->next) + 1) : (0);
}
