/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:19:31 by khooftma          #+#    #+#             */
/*   Updated: 2026/05/29 15:29:57 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static size_t	opt_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
// Eigen ft_strcmp om headers schoon te houden
static int	opt_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// Onthoudt de vorige operatie zonder globale variabelen
static char	*get_last_op(char *new_op, int set)
{
	static char	*last_op = NULL;

	if (set)
		last_op = new_op;
	return (last_op);
}

// Centrale print-functie die alles optimaliseert
void	write_op(char *op)
{
	char	*last;

	last = get_last_op(NULL, 0);
	if (!last)
	{
		get_last_op(op, 1);
		return ;
	}
	// 1. Combineren naar dubbele rotaties / swaps
	if ((opt_strcmp(last, "ra") == 0 && opt_strcmp(op, "rb") == 0)
		|| (opt_strcmp(last, "rb") == 0 && opt_strcmp(op, "ra") == 0))
		return (write(1, "rr\n", 3), get_last_op(NULL, 1), (void)0);
	if ((opt_strcmp(last, "rra") == 0 && opt_strcmp(op, "rrb") == 0)
		|| (opt_strcmp(last, "rrb") == 0 && opt_strcmp(op, "rra") == 0))
		return (write(1, "rrr\n", 4), get_last_op(NULL, 1), (void)0);
	if ((opt_strcmp(last, "sa") == 0 && opt_strcmp(op, "sb") == 0)
		|| (opt_strcmp(last, "sb") == 0 && opt_strcmp(op, "sa") == 0))
		return (write(1, "ss\n", 3), get_last_op(NULL, 1), (void)0);

	// 2. Onnodige, elkaar opheffende operaties volledig wegstrepen (Flashes warnings weg!)
	if ((opt_strcmp(last, "ra") == 0 && opt_strcmp(op, "rra") == 0)
		|| (opt_strcmp(last, "rra") == 0 && opt_strcmp(op, "ra") == 0)
		|| (opt_strcmp(last, "rb") == 0 && opt_strcmp(op, "rrb") == 0)
		|| (opt_strcmp(last, "rrb") == 0 && opt_strcmp(op, "rb") == 0)
		|| (opt_strcmp(last, "pa") == 0 && opt_strcmp(op, "pb") == 0)
		|| (opt_strcmp(last, "pb") == 0 && opt_strcmp(op, "pa") == 0))
		return (get_last_op(NULL, 1), (void)0);

	// 3. Geen match? Print de vorige en sla de nieuwe op
	write(1, last, opt_strlen(last));
	write(1, "\n", 1);
	get_last_op(op, 1);
}

// Leegt de buffer aan het einde van het programma
void	flush_op(void)
{
	char	*last;

	last = get_last_op(NULL, 0);
	if (last)
	{
		write(1, last, opt_strlen(last));
		write(1, "\n", 1);
	}
}