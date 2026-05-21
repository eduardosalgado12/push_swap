#include "push_swap.h"

bool	stack_is_sorted(t_stack *sa)
{
	if (!sa)
		return (true);
	while (sa->next)
	{
		if (sa->value > sa->next->value)
			return (false);
		sa = sa->next;
	}
	return (true);
}

int	stack_len(t_stack *sa)
{
	int	count;

	count = 0;
	while (sa)
	{
		count++;
		sa = sa->next;
	}
	return (count);
}

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	// 1. Se a pilha tiver menos de 2 elementos, não faz nada e sai.
	if (!stack || !*stack || !(*stack)->next)
		return ;

	// 2. Dar nome aos bois: identificar quem é o 1º e o 2º.
	first = *stack;
	second = first->next;

	// 3. O 1º passa a apontar para a frente do 2º (para o 3º elemento).
	first->next = second->next;

	// 4. Se existir um 3º elemento, ele agora tem de apontar para trás, para o 1º.
	if (second->next)
		second->next->prev = first;

	// 5. O 2º elemento passa a apontar para trás, para onde o 1º apontava (NULL).	
	second->prev = first->prev;

	// 6. O 2º elemento passa a apontar para a frente, para o 1º.
	second->next = first;

	// 7. O 1º elemento passa a apontar para trás, para o 2º.
	first->prev = second;

	// 8. O topo da pilha passa a ser, oficialmente, o 2º elemento.
	*stack = second;
}

second->next = first;  // O 2º mete-se à frente do 1º
first->prev = second;  // O 1º diz: "OK, agora tu estás atrás de mim"
*stack = second;       // O árbitro diz: "O 2º é o novo líder da pilha"
