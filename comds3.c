/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comds3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:32:48 by melkarmi          #+#    #+#             */
/*   Updated: 2021/05/30 17:57:31 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ra(t_data *data)
{
	t_stack	*tmp;
	t_stack	*tt;

	if (data->a)
	{
		tmp = new_node((data->a)->num);
		addback(&(data->a), tmp);
		tt = data->a;
		data->a = (data->a)->next;
		free(tt);
	}
}

int	tabsize(char **str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}

t_stack	*reverse(t_stack *head, int k)
{
	t_stack	*current;
	t_stack	*next;
	t_stack	*prev;
	int		count;

	current = head;
	next = NULL;
	prev = NULL;
	count = 0;
	if (!head)
		return (NULL);
	while (current != NULL && count < k)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}
	if (next != NULL)
		head->next = reverse(next, k);
	return (prev);
}
