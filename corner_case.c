/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corner_case.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:47:14 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/02 19:03:48 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	corner_case(t_s *a, int index)
{
	t_s	*tmp;
	int	i;

	tmp = a;
	i = 0;
	while (tmp)
	{
		if (tmp->index == i)
			i++;
		tmp = tmp->next;
	}
	if (i == index + 1)
		return (1);
	else
		return (0);
}

int	if_close_to_sorted(t_s *a, int max_index, int min_index, int len)
{
	t_s	*tmp;
	t_s	*prev_start;
	int	i;

	prev_start = a;
	tmp = a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = prev_start;
	tmp = find_min(tmp, min_index);
	i = 0;
	while (max_index--)
	{
		if (tmp->index == i)
			i++;
		tmp = tmp->next;
	}
	tmp->next = NULL;
	if (i == len)
		return (1);
	return (0);
}

t_s	*find_min(t_s *tmp, int min_index)
{
	while (tmp)
	{
		if (min_index == tmp->index)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

t_s	*clone_struct(t_s *a)
{
	t_s	*new;
	t_s	*node;
	t_s	*tmp_a;

	new = NULL;
	tmp_a = a;
	while (tmp_a)
	{
		node = ft_lstnew(tmp_a->num);
		if (!node)
		{
			free_lst(&new);
			return (NULL);
		}
		node->index = tmp_a->index;
		ft_lstadd_back(&new, node);
		tmp_a = tmp_a->next;
	}
	return (new);
}
