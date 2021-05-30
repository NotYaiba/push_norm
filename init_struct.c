/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 19:04:45 by melkarmi          #+#    #+#             */
/*   Updated: 2021/05/30 19:32:06 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_struct2(t_data *data)
{
	data->chunkcopy = copy_linkedlist(reverse(data->chunk, \
	stack_len(data->chunk)));
}

t_stack	*convert_input(int ac, char **av)
{
	char		**tab;
	t_stack		*tmp;

	tab = NULL;
	if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		tmp = array_to_list2(tab, tabsize(tab));
	}
	else
		tmp = array_to_list(av, ac);
	return (tmp);
}

int	is_there(t_stack *stack, int min, int max)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->num <= max && tmp->num >= min)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	init_struct3(t_data *data)
{
	data->a = NULL;
	data->cmds = NULL;
	data->b = NULL;
	data->chunk = NULL;
}
