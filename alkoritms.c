/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alkoritms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:16:55 by kvoznese          #+#    #+#             */
/*   Updated: 2024/05/28 17:00:10 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_s **a, t_s **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_s **a, t_s **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
void	push(t_s **from, t_s **to)
{
	t_s *tmp_from;
	t_s *tmp_to;
	
	tmp_from = *from;
	tmp_to = *to;
	*from = (*from)->next;
	*to = tmp_from;
	(*to)->next = tmp_to;
}

void	ra(t_s **a)
{
	rotate(a, 1);
	write(1, "ra\n", 3);
}

void	rb(t_s **b, int how_many_times)
{
	rotate(b, how_many_times);
	while (how_many_times)
	{	
		write(1, "rb\n", 3);
		how_many_times--;
	}
}

void	rotate(t_s **stack, int how_many_times)
{
	t_s *new_start;
	t_s *tail;

	while (how_many_times)
	{
		if ((*stack)->next)
		{
			new_start = (*stack)->next;
			tail = (*stack);
			while (tail && tail->next)
				tail = tail->next;
			tail->next = *stack;
			(*stack)->next = NULL;
			*stack = new_start;
		}
		how_many_times--;
	}
}

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

void	rrb(t_s **b, int how_many_times)
{
	reverse_rotate(b, how_many_times);
	while (how_many_times)
	{
		write(1, "rrb\n", 4);
		how_many_times--;
	}
}
