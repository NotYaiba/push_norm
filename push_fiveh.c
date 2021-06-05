/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_fiveh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 19:04:54 by melkarmi          #+#    #+#             */
/*   Updated: 2021/06/05 18:40:48 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_chunk(int min, int max, t_data *data)
{
	int	f_index;
	int	s_index;

	f_index = find_index_top_range(data->a, min, max);
	s_index = find_index_bot_range(data->a, min, max, f_index);
	if (f_index >= 0 && s_index > 0 )
	{
		if (f_index <= s_index)
		{
			f_index -= 1;
			while (f_index--)
				execute_ya("ra", data);
		}
		else if (f_index > s_index)
		{
			s_index = stack_len(data->a) - s_index + 1;
			while (s_index--)
				execute_ya("rra", data);
		}
	}
}

void	move_all_to(t_data *data)
{
	init_struct2(data);
	while (data->chunkcopy)
	{
		data->i = 0;
		while (data->i < (data->chunkcopy)->num)
		{
			data->index = find_max(data->b);
			if (data->index <= stack_len(data->b) / 2)
			{
				data->index -= 1;
				while (data->index --)
					execute_ya("rb", data);
			}
			else
			{
				data->index = stack_len(data->b) - data->index + 1;
				while (data->index--)
					execute_ya("rrb", data);
			}
			execute_ya("pa", data);
			data->i++;
		}
		data->chunkcopy = (data->chunkcopy)->next;
	}
}

void	find_chunk(t_data *data)
{
	int		min;
	int		plus;
	int		max;
	int		cnt;
	int		len;

	cnt = 0;
	min = find_min_val(data->a);
	plus = stack_len(data->a) / 15;
	max = min + plus;
	len = stack_len(data->a);
	while (data->a)
	{
		while (is_there(data->a, min, max) == 1)
		{
			move_chunk(min, max, data);
			execute_ya("pb", data);
			cnt++;
		}
		addback(&(data->chunk), new_node(cnt));
		cnt = 0;
		min += plus;
		max += plus;
	}
	// move_all_to(data);
}

int	find_index_top_range(t_stack *stack, int min, int max)
{
	t_stack	*tmp;
	int		cnt;

	cnt = 1;
	tmp = stack;
	while (tmp)
	{
		if (tmp->num <= max && tmp->num >= min)
			return (cnt);
		cnt++;
		tmp = tmp->next;
	}
	return (0);
}

int	find_index_bot_range(t_stack *stack, int min, int max, int i)
{
	t_stack	*tmp;
	int		cnt;
	int		val;

	val = 0;
	cnt = 1;
	tmp = stack;
	while (tmp)
	{
		if (min <= tmp->num && max >= tmp->num && cnt != i)
			val = tmp->num;
		cnt++;
		tmp = tmp->next;
	}
	tmp = stack;
	cnt = 1;
	while (tmp)
	{
		if (val == tmp->num)
			return (cnt);
		cnt++;
		tmp = tmp->next;
	}
	return (cnt);
}
