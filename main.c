/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:26:18 by edsalgad          #+#    #+#             */
/*   Updated: 2026/06/06 15:37:33 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const char	*get_strat_name(t_strategy strat)
{
	const char	*strats[4] = {
		"Adaptive / O(n\xe2\x88\x9an)",
		"Simple Sort / O(n\xc2\xb2)",
		"Medium Sort / O(n\xe2\x88\x9an)",
		"Quicksort / O(n log n)"};

	return (strats[strat]);
}

void	print_bench(t_bench *bench, t_strategy strat)
{
	if (!bench || !bench->active)
		return ;
	fprintf(stderr, "[bench] disorder:  %.2f%%\n", bench->disorder * 100);
	fprintf(stderr, "[bench] strategy:  %s\n", get_strat_name(strat));
	fprintf(stderr, "[bench] total_ops: %d\n", bench->total_ops);
	fprintf(stderr, "[bench] sa:  %d sb:  %d ss:  %d pa:  %d pb:  %d\n",
		bench->sa, bench->sb, bench->ss, bench->pa, bench->pb);
	fprintf(stderr, "[bench] ra:  %d rb:  %d rr:  %d rra: %d rrb: %d rrr: %d\n",
		bench->ra, bench->rb, bench->rr, bench->rra, bench->rrb,
		bench->rrr);
}

static void	execute_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	bench->disorder = disorder_metric(*a);
	if (ft_lstsize(*a) <= 3)
		sort_two_or_three(a, bench);
	assign_indices(*a);
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
	if (argc > 1 && ft_strcmp(argv[1], "--bench") == 0)
	{
		bench.active = true;
		argv++; // Sla "-b" over voor de getalleninvoer
		argc--; // Verminder het aantal argumenten
	}
	if (!stack_init(argc, argv, &a, &bench) || !a)
		return (write(2, "Error\n", 6), 1);
	if (!stack_sorted(a))
		execute_sort(&a, &b, &bench);
	if (bench.active)
		print_bench(&bench, bench.strat);
	return (free_stack(&a), 0);
}
