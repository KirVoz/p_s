/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcoritms2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:35:20 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/02 19:12:40 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_s **stack, int how_many_times)
{
	t_s	*cur;
	t_s	*prev;

	while (how_many_times)
	{
		cur = *stack;
		while (cur->next)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = NULL;
		cur->next = *stack;
		*stack = cur;
		how_many_times--;
	}
}

void	rrb_rra(t_s **b, int how_many_times, int num)
{
	reverse_rotate(b, how_many_times);
	while (how_many_times)
	{
		if (num == 1)
			write(1, "rrb\n", 4);
		else
			write(1, "rra\n", 4);
		how_many_times--;
	}
}

void	sa(t_s **a)
{
	t_s	*first;
	t_s	*second;

	if (*a && (*a)->next)
	{
		first = *a;
		second = (*a)->next;
		first->next = second->next;
		second->next = first;
		*a = second;
		write(1, "sa\n", 3);
	}
}
