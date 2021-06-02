/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:43:00 by melkarmi          #+#    #+#             */
/*   Updated: 2021/06/02 14:09:20 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	addback(t_stack **alst, t_stack *new)
{
	t_stack	*n;

	n = *alst;
	if (!new)
		return ;
	if (!*alst)
		(*alst) = new;
	else
	{
		while (n->next)
			n = n->next;
		n->next = new;
	}
}

void	add_front(t_stack **alst, t_stack *new)
{
	t_stack	*n;

	n = new;
	n->next = *alst;
	*alst = n;
}

t_stack	*new_node(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->num = content;
	new->content = NULL;
	new->next = NULL;
	return (new);
}

t_stack	*array_to_list(char **array, int size)
{
	int		i;
	t_stack	*stack;

	i = 2;
	stack = new_node(ft_atoii(array[1]));
	while (i < size)
	{
		addback(&stack, new_node(ft_atoii(array[i])));
		i++;
	}
	return (stack);
}

t_stack	*array_to_list2(char **array, int size)
{
	int		i;
	t_stack	*stack;

	stack = new_node(ft_atoii(array[0]));
	i = 1;
	while (i < size)
	{
		addback(&stack, new_node(ft_atoii(array[i])));
		i++;
	}
	return (stack);
}
