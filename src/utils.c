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

static long long int		ft_atoi_ll(const char *str)
{
	int				signe;
	long long int	r;

	signe = 1;
	while ((*str == ' ' || *str == '\n' || *str == '\t' || *str == '\f' ||
				*str == '\r' || *str == '\v') && *str != '\0')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signe = -1;
		str++;
	}
	r = 0;
	while (*str >= '0' && *str <= '9')
	{
		r = r * 10;
		r = r + ((int)*str - 48);
		str++;
	}
	return (r * signe);
}

int								is_number(char *s)
{
	int		n;

	if (s == NULL)
		return (0);
	if (*s == '-' || *s == '+')
		s++;
	n = 0;
	while (*s != '\0')
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
		n++;
	}
	if (n == 0)
		return (0);
	return (1);
}

static int						not_bigger_than_int(char *s)
{
	long long int		lli;
	static const int	int_max = 2147483647;
	static const int	int_min = -2147483648;

	if (!is_number(s))
		return (0);
	if (ft_strlen(s) > 11)
		return (0);
	lli = ft_atoi_ll(s);
	if (lli >= int_min && lli <= int_max)
		return (1);
	return (0);
}

int								arg_valid(char **av)
{
	int					i;

	i = 1;
	while (av[i])
	{
		if (!not_bigger_than_int(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int								repeated(char **av)
{
	int					i;
	int					j;
	int					num;

	i = 1;
	while (av[i])
	{
		num = ft_atoi(av[i]);
		j = i + 1;
		while (av[j])
		{
			if (num == ft_atoi(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int					sorted(t_lst *l)
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
