/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 19:38:35 by melkarmi          #+#    #+#             */
/*   Updated: 2021/06/05 20:21:46 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static void	printret(t_data *data)
{
	if (is_sorted(data->a) == 0)
		printf("KO\n");
	else
		printf("OK\n");
}

int	main(int ac, char **av)
{
	int		i;
	char	*line;
	t_data	*data;

	data = malloc(sizeof(t_data));
	init_struct3(data);
	if (check_errors(av, ac) == 0)
		return (0);
	data->a = convert_input(ac, av);
	while (1)
	{
		if (is_sorted(data->a) == 1 && stack_len(data->a) == ac - 1)
		{
			printf("OK\n");
			return (1);
		}
		i = get_next_line(0, &line);
		exec_inst(line, data);
		if (i == 0)
			break ;
	}
	printret(data);
	return (0);
}
