/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comds2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:31:32 by melkarmi          #+#    #+#             */
/*   Updated: 2021/05/30 16:31:55 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	rb(t_data *data)
{
	t_stack	*tmp;
	t_stack	*tt;

	if (data->b)
	{
		tmp = new_node((data->b)->num);
		addback(&(data->b), tmp);
		tt = data->b;
		data->b = (data->b)->next;
		free(tt);
	}
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
}

void	rra(t_data *data)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = NULL;
	tmp2 = data->a;
	while ((data->a)->next)
		data->a = (data->a)->next;
	if (data->a)
	{
		tmp = new_node((data->a)->num);
		data->a = tmp2;
		add_front(&(data->a), tmp);
		removelast(&data->a);
	}
}

void	rrb(t_data *data)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = NULL;
	tmp2 = data->b;
	if (!(data->b))
		return ;
	while ((data->b)->next)
		data->b = (data->b)->next;
	if (data->b)
	{
		tmp = new_node((data->b)->num);
		data->b = tmp2;
		add_front(&(data->b), tmp);
		removelast(&(data->b));
	}
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
}
