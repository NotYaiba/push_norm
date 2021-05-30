/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 19:39:56 by melkarmi          #+#    #+#             */
/*   Updated: 2021/05/30 19:49:31 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "get_next_line.h"
# include "stdio.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	char			*content;
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*cmds;
	t_stack	*chunk;
	t_stack	*chunkcopy;
	int		rmin;
	int		rmax;
	int		index_min;
	int		index_max;
	int		index;
	int		i;
}				t_data;

t_stack	*convert_input(int ac, char **av);
void	init_struct3(t_data *data);
void	init_struct2(t_data *data);
void	push_half(int half, t_data *data);
int		tabsize (char **str);
void	execute_ya(char *str, t_data *data);
t_stack	*copy_linkedlist(t_stack *stack);
int		find_max_chunk(int stop, t_data *data);
int		is_there(t_stack *stack, int min, int max);
t_stack	*array_to_list2(char **array, int size);
int		find_index_top_range(t_stack *stack, int min, int max);
int		find_index_bot_range(t_stack *stack, int min, int max, int first);
t_stack	*optimize(t_data *data);
int		find_index_top(t_stack *stack, int max);
int		find_index_bot(t_stack *stack, int max, int first);
int		isdigit(int cc);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		check_errors(char **av, int size);
void	move_to_top(t_data *data);
int		find_max(t_stack *stack);
int		find_min(t_stack *stack);
void	print_list2(t_stack *stack);
void	sort_more(t_data *data);
void	sort_four(t_data *data);
void	sort_three(t_stack *stack, t_data *data);
t_stack	*new_node2(char *content);
t_stack	*new_node(int content);
void	exec_inst(char *line, t_data *data);
char	**ft_split(char const *str, char c);
void	sort_linked(t_stack **start);
void	swap(t_stack *a, t_stack *b);
int		find_middle(t_stack *stack, t_data *data);
void	addback(t_stack **alst, t_stack *new);
int		ft_atoii(const char *s);
t_stack	*array_to_list(char **array, int size);
void	print_list(t_stack *stack);
void	add_front(t_stack **alst, t_stack *new);
void	removelast(t_stack **head);
int		is_sorted(t_stack *stack);
int		stack_len(t_stack *stack);
int		find_max_val(t_stack *stack);
int		find_min_val(t_stack *stack);
void	find_chunk(t_data *data);
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);
void	case1(t_data *data);
void	case2(t_data *data);
void	case5(t_data *data);
void	case3(t_data *data);
void	case4(t_data *data);
void	move_to_b(int min, t_data *data);
int		move_to_top2(int *i, t_data *data);
t_stack	*reverse(t_stack *head, int k);

#endif
