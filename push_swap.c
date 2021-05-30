/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:21:05 by melkarmi          #+#    #+#             */
/*   Updated: 2021/05/30 19:31:01 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case4(t_data *data)
{
	addback(&(data->cmds), new_node2("sa"));
	addback(&(data->cmds), new_node2("ra"));
}

int	main (int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	init_struct3(data);
	data->a = convert_input(ac, av);
	if (check_errors(av, ac) == 0)
		return (0);
	if (is_sorted(data->a))
		return (0);
	if (stack_len(data->a) == 3)
		sort_three(data->a, data);
	else if (stack_len(data->a) == 4)
		sort_four(data);
	else if (stack_len(data->a) <= 100)
		sort_more(data);
	else
		find_chunk(data);
	print_list2(optimize(data));
}

t_stack	*optimize(t_data *data)
{
	t_stack	*tmp;

	tmp = NULL;
	while (data->cmds)
	{
		if ((data->cmds)->next && ((!strcmp((data->cmds)->content, "ra") && \
		!strcmp((data->cmds)->next->content, "rb")) || \
		(!strcmp((data->cmds)->content, "rb") && \
		!strcmp((data->cmds)->next->content, "ra"))))
		{
			addback(&tmp, new_node2("rr"));
			(data->cmds) = (data->cmds)->next;
		}
		else if ((data->cmds)->next && ((!strcmp((data->cmds)->content, "rra") \
		&& !strcmp((data->cmds)->next->content, "rrb")) || (!strcmp((data->cmds) \
		->content, "rrb") && !strcmp((data->cmds)->next->content, "rra"))))
		{
			addback(&tmp, new_node2("rrr"));
			(data->cmds) = (data->cmds)->next;
		}
		else
			addback(&tmp, new_node2((data->cmds)->content));
		(data->cmds) = (data->cmds)->next;
	}
	return (tmp);
}
