/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_maker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:06:57 by kvoznese          #+#    #+#             */
/*   Updated: 2024/05/28 17:31:36 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		list_length(t_s *a)
{
	t_s *tmp;
	int i;
	
	i = 0;
	tmp = a;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	make_array_great_again(int *arr, t_s *a)
{
	int len;
	int i;
	int tmp;
	
	len = list_length(a);
	while (--len)
	{
		i = 0;
		while (i < len)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
			i++;
		}
	}
}
int		*make_array(t_s *a)
{
	t_s *tmp;
	int len;
	int	*array;
	int i;
	
	i = 0;
	len = list_length(a);
	array = malloc(sizeof(int) * len);
	tmp = a;
	while (tmp)
	{
		array[i] = tmp->num;
		tmp = tmp->next;
		i++;
	}
	make_array_great_again(array, a);
	return (array);
}

void	make_indexes_for_struct(t_s *a)
{
	t_s	*tmp;
	int	*arr;
	int i;
	int l;

	l = list_length(a);
	arr = make_array(a);
	tmp = a;
	while (a)
	{
		i = 0;
		while (i < l)
		{
			if (arr[i] == a->num)
			{
				a->index = i;
				break ;
			}
			i++;
		}
		a = a->next;
	}
	a = tmp;
}