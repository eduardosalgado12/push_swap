/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:26:18 by edsalgad          #+#    #+#             */
/*   Updated: 2026/06/09 14:52:05 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const char	*get_strat_name(t_strategy strat)
{
	const char	*strats[4] = {
		"Adaptive Sort / O(n\xe2\x88\x9an)",
		"Simple Sort / O(n\xc2\xb2)",
		"Medium Sort / O(n\xe2\x88\x9an)",
		"Complex Sort / O(n log n)"};

	return (strats[strat]);
}

void	print_bench(t_bench *bench, t_strategy strat)
{
	if (!bench || !bench->active)
	return ;
	ft_printf("[bench] disorder:  %.2f%%\n", bench->disorder * 100, stderr);
	ft_printf("[bench] strategy:  %s\n", get_strat_name(strat), stderr);
	ft_printf("[bench] total_ops: %d\n", bench->total_ops, stderr);
	ft_printf("[bench] sa:  %d sb:  %d ss:  %d pa:  %d pb:  %d\n",
		bench->sa, bench->sb, bench->ss, bench->pa, bench->pb, stderr);
	ft_printf("[bench] ra:  %d rb:  %d rr:  %d rra: %d rrb: %d rrr: %d\n",
		bench->ra, bench->rb, bench->rr, bench->rra, bench->rrb,
		bench->rrr, stderr);
}

static void	execute_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	bench->disorder = disorder_metric(*a);

	assign_indices(*a);
	if (bench->strat == STRAT_SIMPLE)
			if (ft_lstsize(*a) <= 3)
			sort_two_or_three(a, bench);
			else if (ft_lstsize(*a) == 4 || ft_lstsize(*a) == 5)
			sort_five(a , b, bench);
			else
			selection_sort(a, b, bench);
	else if (bench->strat == STRAT_MEDIUM)
			if (ft_lstsize(*a) <= 3)
			sort_two_or_three(a, bench);
			else if (ft_lstsize(*a) == 4 || ft_lstsize(*a) == 5)
			sort_five(a , b, bench);
			else
			(chunk_sort(a, b, bench));
	else if (bench->strat == STRAT_COMPLEX)
			if (ft_lstsize(*a) <= 3)
			sort_two_or_three(a, bench);
			else if (ft_lstsize(*a) == 4 || ft_lstsize(*a) == 5)
			sort_five(a , b, bench);
			else
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
