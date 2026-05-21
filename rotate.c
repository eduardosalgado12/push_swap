#include "push_swap.h"

void rotate(t_stack **stack)
{
	t_stack	*first;
    t_stack	*last;

    if (!stack || !*stack || !(*stack)->next)
		return;


    first = *stack;
    first = 0x100;
    first->next = 0x200;
    
    last = *stack;
    while(last->next)
        last = last->next;
      
    *stack = first->next; //o primeiro da fila passa a ser o segundo
    *stack = 0x200;
    (*stack)->prev = NULL; // como ja atualizamos o topo da lista, temos de alterar o prev dela para NULL

    last->next = first; // o ultimo agarra o antigo primeiro, passando a ser o ultimo

    
    first->next = NULL; // o primeiro agora passa a ser o ultimo
    first->prev = last; // o prev do primeiro passa a ser o antigo ultimo

}

void reverse_rotate(t_stack **stack)
{
	t_stack	*first;
    t_stack	*last;

    if (!stack || !*stack || !(*stack)->next)
		return;
    first = *stack;
    last = *stack;

    while(last->next)
        last = last->next;
      
    last->prev->next = NULL; // Desconecta o último elemento do penúltimo
    
    last->next = first; // Configura o último como o novo topo
    last->prev = NULL;

    first->prev = last; //Atualiza o antigo topo para apontar para o novo topo

    *stack = last;
}