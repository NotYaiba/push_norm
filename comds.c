/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:20:49 by melkarmi          #+#    #+#             */
/*   Updated: 2021/05/30 16:33:06 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sa(t_data *data)
{
	int	t;

	t = 0;
	if (data->a != NULL && (data->a)->next != NULL)
	{
		t = (data->a)->num;
		(data->a)->num = (data->a)->next->num;
		(data->a)->next->num = t;
	}
}

void	sb(t_data *data)
{
	int	t;

	t = 0;
	if (data->b != NULL && (data->b)->next != NULL)
	{
		t = (data->b)->num;
		(data->b)->num = (data->b)->next->num;
		(data->b)->next->num = t;
	}
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
}

void	pa(t_data *data)
{
	t_stack	*tmp;
	t_stack	*tt;

	if (data->b)
	{
		tmp = new_node((data->b)->num);
		add_front(&(data->a), tmp);
		tt = data->b;
		data->b = (data->b)->next;
		free(tt);
	}
}

void	pb(t_data *data)
{
	t_stack	*tmp;
	t_stack	*tt;

	if (data->a)
	{
		tmp = new_node((data->a)->num);
		add_front(&(data->b), tmp);
		tt = data->a;
		data->a = (data->a)->next;
		free(tt);
	}
}
