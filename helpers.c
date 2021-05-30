/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   helpers.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: melkarmi <melkarmi@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/05/29 16:19:59 by melkarmi		  #+#	#+#			 */
/*   Updated: 2021/05/29 16:20:02 by melkarmi		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		printf("%d\n", tmp->num);
		tmp = tmp->next;
	}
}

void	print_list2(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
}

void	removelast(t_stack **head)
{
	t_stack	*second_last;

	second_last = *head;
	 if (*head == NULL)
		return ;
	if ((*head)->next == NULL)
		return ;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	free (second_last->next);
	second_last->next = NULL;
}

int	is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	stack_len(t_stack *stack)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
