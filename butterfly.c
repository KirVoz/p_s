/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:13:22 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/02 19:02:26 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	magic(int n)
{
	int	m;

	m = 1;
	if (n < 50)
		m = 3 + (n - 6) / 7;
	else if (n >= 50 && n < 100)
		m = 10 + (n - 50) / 8;
	else if (n >= 100 && n < 350)
		m = 18 + (n - 100) / 9;
	else if (n >= 350 && n <= 500)
		m = 27 + (n - 350) / 15;
	else if (n > 500)
		m = 37 + (n - 500) / 20;
	return (m);
}

void	butterfly_sort(t_s **a, t_s **b)
{
	int	m;
	int	i;

	i = 0;
	m = magic(list_length(*a));
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			rb_ra(b, 1, 1);
			i++;
		}
		else if ((*a)->index <= i + m)
		{
			pb(a, b);
			i++;
		}
		else
			rb_ra(a, 1, 0);
		m = magic(list_length(*a));
	}
}

void	back_to_a(t_s **a, t_s **b, int max_index)
{
	while (max_index >= 0 && *b)
	{
		if (max_index != (*b)->index)
			rotate_up_or_down(b, max_index);
		max_index--;
		pa(a, b);
	}
}

void	rotate_up_or_down(t_s **b, int max_index)
{
	t_s	*tmp;
	int	i;

	tmp = *b;
	i = 0;
	while (*b && tmp->index != max_index)
	{
		i++;
		tmp = tmp->next;
	}
	if (i <= list_length(*b) / 2)
		rb_ra(b, i, 1);
	else
		rrb_rra(b, list_length(*b) - i, 1);
}
