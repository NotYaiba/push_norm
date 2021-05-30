/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:57:51 by melkarmi          #+#    #+#             */
/*   Updated: 2021/05/30 17:57:55 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack, t_data *data)
{
	t_stack	*f;
	t_stack	*tt;

	f = stack;
	tt = f->next;
	if (f->num > tt->num && tt->num < tt->next->num && f->num < tt->next->num)
		case1(data);
	else if (f->num > tt->num && tt->num > tt->next->num)
		case2(data);
	else if (f->num > tt->num && tt->num < tt->next->num && f->num > \
	tt->next->num)
		case3(data);
	else if (f->num < tt->num && f->num < tt->next->num)
		case4(data);
	else if (f->num < tt->num)
		case5(data);
}

void	case1(t_data *data)
{
	addback(&(data->cmds), new_node2("sa"));
}

void	case3(t_data *data)
{
	addback(&(data->cmds), new_node2("ra"));
}

void	case2(t_data *data)
{
	addback(&(data->cmds), new_node2("sa"));
	addback(&(data->cmds), new_node2("rra"));
}

void	case5(t_data *data)
{
	addback(&(data->cmds), new_node2("rra"));
}
