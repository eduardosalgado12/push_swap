/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 15:58:12 by khooftma          #+#    #+#             */
/*   Updated: 2026/06/06 16:04:08 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	execute_op_sub(t_stack **a, t_stack **b, char *line, t_bench *bench)
{
	if (ft_strcmp(line, "rb\n") == 0)
		rb(b, bench);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(a, b, bench);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(a, bench);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(b, bench);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(a, b, bench);
	else
		return (0);
	return (1);
}

static int	execute_op(t_stack **a, t_stack **b, char *line, t_bench *bench)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(a, bench);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(b, bench);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(a, b, bench);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(a, b, bench);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(a, b, bench);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(a, bench);
	else
		return (execute_op_sub(a, b, line, bench));
	return (1);
}

static bool	read_and_execute(t_stack **a, t_stack **b, t_bench *bench)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (ft_strcmp(line, "\n") == 0)
		{
			free(line);
			line = get_next_line(0);
			continue ;
		}
		if (!execute_op(a, b, line, bench))
		{
			free(line);
			return (false);
		}
		free(line);
		line = get_next_line(0);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_bench	dummy_bench;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	ft_bzero(&dummy_bench, sizeof(t_bench));
	dummy_bench.is_checker = true;
	if (!stack_init(argc, argv, &a, &dummy_bench) || !a)
		return (1);
	if (!read_and_execute(&a, &b, &dummy_bench))
		return (free_stack(&a), free_stack(&b), write(2, "Error\n", 6), 1);
	if (stack_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free_stack(&a), free_stack(&b), 0);
}
