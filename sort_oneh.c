/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_oneh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:58:08 by melkarmi          #+#    #+#             */
/*   Updated: 2021/06/02 15:29:17 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_more(t_data *data)
{
	int	i;
	int	half;

	i = 0;
	half = stack_len(data->a) / 2 - 1;
	push_half(half, data);
	while (data->b)
		move_to_top2(&i, data);
	while (i--)
		 execute_ya("ra", data);
	move_to_b(find_min_val(data->a), data);
	i = 0;
	while (data->b)
		move_to_top2(&i, data);
	while (i--)
		execute_ya("ra", data);
}

void	push_half(int half, t_data *data)
{
	int	mid;
	int	len;
	int	f_index;
	int	s_index;

	mid = find_middle(data->a, data);
	len = stack_len(data->a);
	while (half > 0)
	{
		f_index = find_index_top(data->a, mid) - 1;
		s_index = len - find_index_bot(data->a, mid, \
		find_index_top(data->a, mid)) + 1;
		if (f_index >= s_index)
		{
			while (s_index-- > 0)
				execute_ya("rra", data);
		}
		else if (f_index < s_index)
		{
			while (f_index-- > 0)
				execute_ya("ra", data);
		}
		execute_ya("pb", data);
		half--;
	}
}

int	find_index_top(t_stack *stack, int max)
{
	t_stack	*tmp;
	int		cnt;

	cnt = 1;
	tmp = stack;
	while (tmp)
	{
		if (max > tmp->num)
			return (cnt);
		tmp = tmp->next;
		cnt++;
	}
	return (0);
}

int	find_index_bot(t_stack *stack, int max, int first)
{
	t_stack	*tmp;
	int		cnt;

	cnt = 1;
	tmp = stack;
	while (tmp)
	{
		if (max > tmp->num && cnt != first)
			max = tmp->num;
		cnt++;
		tmp = tmp->next;
	}
	tmp = stack;
	cnt = 1;
	while (tmp)
	{
		if (max == tmp->num)
			return (cnt);
		cnt++;
		tmp = tmp->next;
	}
	return (cnt);
}

int	find_min(t_stack *stack)
{
	t_stack	*tmp;
	int		cnt;
	int		max;

	cnt = 1;
	max = INT_MAX;
	tmp = stack;
	while (tmp)
	{
		if (max > tmp->num)
			max = tmp->num;
		tmp = tmp->next;
	}
	tmp = stack;
	while (tmp)
	{
		if (max == tmp->num)
			return (cnt);
		cnt++;
		tmp = tmp->next;
	}
	return (cnt);
}
