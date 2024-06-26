/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   almost_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:05:38 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/02 18:37:25 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	almost_sorted(t_s **a)
{
	t_s	*tmp;
	int	i;

	i = 0;
	tmp = *a;
	while (tmp && tmp->index != 0)
	{
		i++;
		tmp = tmp->next;
	}
	if (i <= list_length(*a) / 2)
		rb_ra(a, i, 0);
	else
		rrb_rra(a, list_length(*a) - i, 0);
	exit (1);
}
