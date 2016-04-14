/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 05:34:17 by bndao             #+#    #+#             */
/*   Updated: 2016/04/14 08:45:05 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct		s_lst
{
	int				num;
	struct s_lst	*next;
}					t_lst;


t_lst				*l_new(int n);
t_lst				*init_lst(int ac, char **av);
void				push_back_list(t_lst *b_list, t_lst *new);
int					arg_valid(char **av);
int					repeated(char **av);

#endif
