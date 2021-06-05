/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_oneh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:58:08 by melkarmi          #+#    #+#             */
/*   Updated: 2021/06/05 20:02:48 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_more(t_data *data)
{
	int	i;
	int	half;

	i = 0;
	half = stack_len(data->a) / 2 ;
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
	int	rf = 0;
	int	rs = 0;

	mid = find_middle(data->a, data);
	while (half > 0)
	{
		rf = 0;
		rs = 0;
		len = stack_len(data->a);
		f_index = find_index_top(data->a, mid) ;
		s_index = find_index_bot(data->a, mid, f_index);
		if (f_index	> (len / 2))
		{
			rf = 1;
			f_index = len - f_index + 1;
		}
		else
			f_index -= 1;
		if (s_index > (len / 2))
		{ 
			s_index = len - s_index + 1;
			rs = 1;
		}
		else
			s_index -= 1;

		if (f_index >= s_index)
		{

			if (rs == 1)
			{
				while (s_index-- > 0)
					execute_ya("rra", data);
			}
			else{
				while (s_index-- > 0)
					execute_ya("ra", data);
			}
		}
		else if (f_index < s_index)
		{
			if (rf == 1)
			{
				while (f_index-- > 0)
					execute_ya("rra", data);
			}
			else{
				while (f_index-- > 0)
					execute_ya("ra", data);
			}
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
		if (max > tmp->num )
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
