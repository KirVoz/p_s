/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:08:38 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/02 19:25:09 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	low_num(t_s **a, t_s **b, int max_index)
{
	if (max_index <= 2)
		sort_3(a, 0, max_index);
	else if (max_index <= 4)
		sort_5(a, b, max_index);
}

void	sort_5(t_s **a, t_s **b, int max_index)
{
	t_s	*tmp;
	int	i;

	i = 0;
	tmp = *a;
	while (max_index - 2 > i && tmp->next)
	{
		if (tmp->index == i)
		{
			pb(a, b);
			i++;
		}
		else
			else_5(i, a, max_index);
		tmp = *a;
	}
	sort_3(a, 1, max_index);
	while (*b != NULL)
		pa(a, b);
	exit (1);
}

void	else_5(int i, t_s **a, int max_index)
{
	int	j;

	j = find_two_lowest(a, i);
	if (j <= 3)
		rb_ra(a, j, 0);
	else
		rrb_rra(a, max_index + 1 - j, 0);
}

int	find_two_lowest(t_s **a, int i)
{
	t_s	*tmp;
	int	j;

	j = 0;
	tmp = *a;
	while (i != tmp->index)
	{
		j++;
		tmp = tmp->next;
	}
	return (j);
}

void	sort_3(t_s **a, int overwatch, int max_index)
{
	if ((*a)->index == max_index)
		rb_ra(a, 1, 0);
	else if ((*a)->next->index == max_index)
		rrb_rra(a, 1, 0);
	if ((*a)->next->index < (*a)->index)
		sa(a);
	if (overwatch == 0)
		exit (1);
}
