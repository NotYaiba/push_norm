/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:21:05 by melkarmi          #+#    #+#             */
/*   Updated: 2021/06/02 17:26:15 by melkarmi         ###   ########.fr       */
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
	// if (check_errors(av, ac) == 0)
	// 	return (0);
	// if (is_sorted(data->a))
	// 	return (0);

	// if (stack_len(data->a) == 3)
	// 	sort_three(data->a, data);
	// else if (stack_len(data->a) == 4)
	// 	sort_four(data);
	// else if (stack_len(data->a) <= 100)
	// 	sort_more(data);
	// else
		find_chunk(data);
	// optimize(data);
	// ft_lstclear(&(data->a));
	// data->a = NULL;
	// ft_lstclear(&(data->b));
	// ft_lstclear(&(data->chunk));
	// ft_lstclear(&(data->chunkcopy));
	// data->b = NULL;
	// free(data);
}

void	optimize(t_data *data)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = NULL;
	tmp2 = data->cmds;
	while (tmp2)
	{
		if ((tmp2)->next && ((!strcmp((tmp2)->content, "ra") && \
		!strcmp((tmp2)->next->content, "rb")) || \
		(!strcmp((tmp2)->content, "rb") && \
		!strcmp((tmp2)->next->content, "ra"))))
		{
			addback(&tmp, new_node2("rr"));
			(tmp2) = (tmp2)->next;
		}
		else if ((tmp2)->next && ((!strcmp((tmp2)->content, "rra") \
		&& !strcmp((tmp2)->next->content, "rrb")) || (!strcmp((tmp2) \
		->content, "rrb") && !strcmp((tmp2)->next->content, "rra"))))
		{
			addback(&tmp, new_node2("rrr"));
			(tmp2) = (tmp2)->next;
		}
		else
			addback(&tmp, new_node2((tmp2)->content));
		(tmp2) = (tmp2)->next;
	}
	print_list2(tmp);
	ft_lstclear(&tmp);
	ft_lstclear(&(data->cmds));
}
