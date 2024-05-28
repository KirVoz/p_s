/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:13:22 by kvoznese          #+#    #+#             */
/*   Updated: 2024/05/28 21:20:33 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		magic(int n)
{
	n = 1;
	if (n < 50)
		n = 3 + (n - 6) / 7;
	else if (n >= 50 && n < 100)
		n = 10 + (n - 50) / 8;
	else if (n >= 100 && n <= 350)
		n = 18 + (n - 100) / 9;
	else if (n >= 350 && n <= 500)
		n = 27 + (n - 350) / 15;
	if (n > 500)
		n = 37 + (n - 500) / 20;
	return (n);
}

void	butterfly_sort(t_s **a, t_s **b)
{
	int 	m;
	int		i;
	
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
	t_s *tmp;
	int i;
	
	tmp = *b;
	i  = 0;
	while (*b && tmp->index != max_index)
	{
		i++;
		tmp = tmp->next;
	}
	if (i <= list_length(*b) / 2) // 5 / 2 = 2 >= i
		rb_ra(b, i, 1);
	else
		rrb_rra(b, list_length(*b) - i, 1);
}


// void back_to_a(t_s **a, t_s **b, int max_index)
// {
// 	t_s *tmp;
// 	int i;
	
// 	tmp = *b;
// 	while (max_index >= 0 && *b)
// 	{
// 		i = 0;
// 		while (*b && tmp->next)
// 		{
// 			if (max_index == tmp->index)
// 			{
// 				pa(a, b);
// 				break;
// 			}
// 			i++;
// 			tmp = tmp->next;
// 		}
// 		if (i <= list_length(*b) / 2 && i >= 0)
// 		{
// 			rb(b, i);
// 			pa(a, b);
// 		}
// 		else
// 		{	rrb(b, list_length(*b) - i && i >= 0);
// 			pa(a, b);
// 		}
// 		max_index--;
// 	}
// }

// void	back_to_a(t_s **a, t_s **b, int max_index)
// {
// 	t_s *tmp;
// 	int i;
	
// 	tmp = *b;
// 	while (tmp)
// 	{
// 		i = 0;
// 		while (max_index != tmp->index && tmp->next)
// 		{
// 			tmp = tmp->next;
// 			i++;
// 		}
// 		if (i == list_length(*b))
// 			rrb(b, 1);
// 		else if (list_length(*b) - i < list_length(*b) / 2)
// 			rrb(b, list_length(*b) - i);
// 		else if (list_length(*b) - i > list_length(*b) / 2)
// 			rb(b, i);
// 		max_index--;
// 		pa(a, b);
// 		max_index--;
// 	}
// }


