/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:58:27 by melkarmi          #+#    #+#             */
/*   Updated: 2021/05/30 17:58:30 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	index3(t_data *data)
{
	addback(&(data->cmds), new_node2("rra"));
	addback(&(data->cmds), new_node2("rra"));
	rra(data);
	rra(data);
	if (!is_sorted((data->a)->next))
	{
		addback(&(data->cmds), new_node2("pb"));
		sort_three((data->a)->next, data);
		addback(&(data->cmds), new_node2("pa"));
	}
}

static void	index4(t_data *data)
{
	addback(&(data->cmds), new_node2("rra"));
	rra(data);
	if (!is_sorted((data->a)->next))
	{
		addback(&(data->cmds), new_node2("pb"));
		sort_three((data->a)->next, data);
		addback(&(data->cmds), new_node2("pa"));
	}
}

void	sort_four(t_data *data)
{
	t_stack	*tmp;

	tmp = data->a;
	if (find_min(data->a) == 1)
	{
		addback(&(data->cmds), new_node2("pb"));
		sort_three((data->a)->next, data);
		addback(&(data->cmds), new_node2("pa"));
	}
	else if (find_min(data->a) == 2)
	{
		addback(&(data->cmds), new_node2("sa"));
		sa(data);
		if (!is_sorted((data->a)->next))
		{
			addback(&(data->cmds), new_node2("pb"));
			sort_three((data->a)->next, data);
			addback(&(data->cmds), new_node2("pa"));
		}
	}
	else if (find_min(data->a) == 3)
		index3(data);
	else if (find_min(data->a) == 4)
		index4(data);
	data->a = tmp;
}
