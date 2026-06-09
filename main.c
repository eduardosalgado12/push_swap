/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edsalgad <edsalgad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:26:18 by edsalgad          #+#    #+#             */
/*   Updated: 2026/06/09 16:34:40 by edsalgad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_strat_name(t_strategy strat)
{
	static char	*strats[] = {
		"Adaptive Sort / O(n\xe2\x88\x9an)",
		"Simple Sort / O(n\xc2\xb2)",
		"Medium Sort / O(n\xe2\x88\x9an)",
		"Complex Sort / O(n log n)"
	};

	return (strats[strat]);
}

static void	print_ops(t_bench *b)
{
	ft_putstr_fd("[bench] sa:  ", 2);
	ft_putnbr_fd(b->sa, 2);
	ft_putstr_fd(" sb:  ", 2);
	ft_putnbr_fd(b->sb, 2);
	ft_putstr_fd(" ss:  ", 2);
	ft_putnbr_fd(b->ss, 2);
	ft_putstr_fd(" pa:  ", 2);
	ft_putnbr_fd(b->pa, 2);
	ft_putstr_fd(" pb:  ", 2);
	ft_putnbr_fd(b->pb, 2);
	ft_putstr_fd("\n[bench] ra:  ", 2);
	ft_putnbr_fd(b->ra, 2);
	ft_putstr_fd(" rb:  ", 2);
	ft_putnbr_fd(b->rb, 2);
	ft_putstr_fd(" rr:  ", 2);
	ft_putnbr_fd(b->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(b->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(b->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(b->rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	print_bench(t_bench *bench, t_strategy strat)
{
	if (!bench || !bench->active)
		return ;
	ft_putstr_fd("[bench] disorder:  ", 2);
	ft_putfloat_fd(bench->disorder * 100, 2);
	ft_putstr_fd(" %\n[bench] strategy:  ", 2);
	ft_putstr_fd(get_strat_name(strat), 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(bench->total_ops, 2);
	ft_putstr_fd("\n", 2);
	print_ops(bench);
}

static void	execute_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	bench->disorder = disorder_metric(*a);
	assign_indices(*a);
	if (bench->strat != STRAT_ADAPTIVE)
	{
		if (ft_lstsize(*a) <= 3)
		{
			sort_two_or_three(a, bench);
			return ;
		}
		if (ft_lstsize(*a) == 4 || ft_lstsize(*a) == 5)
		{
			sort_five(a, b, bench);
			return ;
		}
	}
	if (bench->strat == STRAT_SIMPLE)
		selection_sort(a, b, bench);
	else if (bench->strat == STRAT_MEDIUM)
		chunk_sort(a, b, bench);
	else if (bench->strat == STRAT_COMPLEX)
		quick_sort_a(a, b, ft_lstsize(*a), bench);
	else
		adaptive_sort(a, b, bench->disorder, bench);
}

int	main(int argc, char **argv)
{
	t_bench	bench;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	ft_bzero(&bench, sizeof(t_bench));
	if (!stack_init(argc, argv, &a, &bench))
		return (write(2, "Error\n", 6), 1);
	if (!stack_sorted(a))
		execute_sort(&a, &b, &bench);
	if (bench.active)
		print_bench(&bench, bench.strat);
	return (free_stack(&a), 0);
}
