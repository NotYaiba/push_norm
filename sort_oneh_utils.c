/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_oneh_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:50:06 by melkarmi          #+#    #+#             */
/*   Updated: 2021/05/30 18:27:09 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_b(int min, t_data *data)
{
	t_stack	*tmp;
	int		i;

	i = 1;
	tmp = data->a;
	while (tmp)
	{
		if (tmp->num == min)
			break ;
		tmp = tmp->next;
		execute_ya("pb", data);
	}
}

void	push_min(int rmin, int index_min, t_data *data)
{
	if (rmin == 0)
	{
		while (index_min--)
			execute_ya("rb", data);
	}
	else
	{
		while (index_min--)
			execute_ya("rrb", data);
	}
	execute_ya("pa", data);
	execute_ya("ra", data);
}

void	push_max(int rmax, int index_max, t_data *data)
{
	if (rmax == 0)
	{
		while (index_max--)
			execute_ya("rb", data);
	}
	else
	{
		while (index_max--)
			execute_ya("rrb", data);
	}
	execute_ya("pa", data);
}

void	init_struct(t_data *data)
{
	data->index_min = find_min(data->b);
	data->index_max = find_max(data->b);
	data->rmin = 1;
	data->rmax = 1;
}

int	move_to_top2(int *i, t_data *data)
{
	init_struct(data);
	if (data->index_min < (stack_len(data->b) / 2 + 1))
	{
		data->index_min = data->index_min - 1;
		data->rmin = 0;
	}
	else
		data->index_min = stack_len(data->b) - data->index_min + 1;
	if (data->index_max < (stack_len(data->b) / 2 + 1))
	{
		data->index_max = data->index_max - 1;
		data->rmax = 0;
	}
	else
		data->index_max = stack_len(data->b) - data->index_max + 1;
	if (data->index_min < data->index_max)
		push_min(data->rmin, data->index_min, data);
	else
	{
		push_max(data->rmax, data->index_max, data);
		(*i)++;
	}
	return (0);
}
