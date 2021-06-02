/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   helpers3.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: melkarmi <melkarmi@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/05/29 16:20:20 by melkarmi		  #+#	#+#			 */
/*   Updated: 2021/05/29 16:20:22 by melkarmi		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

int	check_errors(char **av, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (isdigit((int)av[i][0]) == 0)
		{
			printf("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	find_max_val(t_stack *stack)
{
	t_stack	*tmp;
	int		max;

	max = INT_MIN;
	tmp = stack;
	while (tmp)
	{
		if (max < tmp->num)
			max = tmp->num;
		tmp = tmp->next;
	}
	return (max);
}

int	find_min_val(t_stack *stack)
{
	t_stack	*tmp;
	int		max;

	max = INT_MAX;
	tmp = stack;
	while (tmp)
	{
		if (max > tmp->num)
			max = tmp->num;
		tmp = tmp->next;
	}
	return (max);
}

int	find_max(t_stack *stack)
{
	t_stack	*tmp;
	int		cnt;
	int		max;

	cnt = 1;
	max = INT_MIN;
	tmp = stack;
	while (tmp)
	{
		if (max < tmp->num)
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

void	execute_ya(char *str, t_data *data)
{
	
	addback(&data->cmds, new_node2(str));
	exec_inst(str, data);
}
