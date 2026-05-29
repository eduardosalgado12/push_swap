#include "push_swap.h"

// Betrouwbare min-zoeker die de positie van het absolute minimum in A vindt
static int	get_min_pos_local(t_stack *stack)
{
	int	min_val;
	int	min_pos;
	int	i;

	if (!stack)
		return (0);
	min_val = stack->value;
	min_pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->value < min_val)
		{
			min_val = stack->value;
			min_pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (min_pos);
}

// Zoekt de positie van het dichtstbijzijnde geldige getal vanaf de top binnen een chunk-limiet
static int	get_closest_in_range(t_stack *stack, int limit)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->index < limit)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

void	selection_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	pos;
	int	size;
	int	total_size;
	int	chunks;
	int	i;
	int	limit;

	total_size = ft_lstsize(*stack_a);
	
	// Bepaal dynamisch het aantal chunks (1 voor kleine stacks, 5 voor grote stacks)
	if (total_size <= 100)
		chunks = 1;
	else
		chunks = 5;
	
	i = 1;
	// Fase 1: Push in chunks naar B (wordt automatisch overgeslagen bij maat 100 omdat i < 1 al vals is)
	while (i < chunks)
	{
		limit = (total_size / chunks) * i;
		while (1)
		{
			pos = get_closest_in_range(*stack_a, limit);
			if (pos == -1)
				break ;
			size = ft_lstsize(*stack_a);
			if (pos <= size / 2)
				while (pos-- > 0)
					ra(stack_a);
			else
				while (pos++ < size)
					rra(stack_a);
			pb(stack_a, stack_b);
		}
		i++;
	}

	// Fase 2: De restanten (of alle elementen bij maat 100) via pure selectie sorteren naar B
	while (ft_lstsize(*stack_a) > 3)
	{
		pos = get_min_pos_local(*stack_a); // HIER lag de fout, we moeten écht het minimum zoeken!
		size = ft_lstsize(*stack_a);
		if (pos <= size / 2)
			while (pos-- > 0)
				ra(stack_a);
		else
			while (pos++ < size)
				rra(stack_a);
		pb(stack_a, stack_b);
	}
	
	// Sorteer de laatste 3 elementen in A
	sort_three(stack_a);

	// Fase 3: Selectiesort (Max Extraction) van B terug naar A
	while (*stack_b)
	{
		int max_index = (*stack_b)->index;
		int max_pos = 0;
		int current_pos = 0;
		t_stack *tmp = *stack_b;
		
		while (tmp)
		{
			if (tmp->index >= max_index)
			{
				max_index = tmp->index;
				max_pos = current_pos;
			}
			tmp = tmp->next;
			current_pos++;
		}
		
		size = ft_lstsize(*stack_b);
		if (max_pos <= size / 2)
			while (max_pos-- > 0)
				rb(stack_b);
		else
			while (max_pos++ < size)
				rrb(stack_b);
		pa(stack_a, stack_b);
	}
}
