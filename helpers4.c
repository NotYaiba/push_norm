/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 20:12:47 by melkarmi          #+#    #+#             */
/*   Updated: 2021/06/05 20:49:53 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	check_str(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (isdigit(str[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

void	sort_five(t_data *data)
{
	push_half(2, data);
	sort_three(data->a, data);
	if (is_sorted(data->b) == 1)
		execute_ya("sb", data);
	execute_ya("pa", data);
	execute_ya("pa", data);
}

void	remove_leaks(t_data *data)
{
	ft_lstclear(&(data->a));
	data->a = NULL;
	ft_lstclear(&(data->b));
	ft_lstclear(&(data->chunk));
	ft_lstclear(&(data->chunkcopy));
	data->b = NULL;
	free(data);
}
