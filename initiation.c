/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:16:14 by kvoznese          #+#    #+#             */
/*   Updated: 2024/05/27 23:06:07 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	if_valid(char *str)
{
	long int	i;

	i = 0;
	if (str[i] == '-' && str[i + 1])
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			exit (1 && write(2, "Error\n", 6));
		i++;
	}
	return (1);
}

int	uniq(int n, t_s *a)
{
	while (a)
	{
		if (a->num == n)
			exit (1 && write(2, "Error\n", 6));
		a = a->next;
	}
	return (1);
}

int	try_add(char *current_str, t_s **a)
{
	int overflow;
	int num;
	t_s *new_node;
	
	overflow = 0;
	if (if_valid(current_str))
	{
		num = ft_atoi(current_str, &overflow);
		if (uniq(num, *a))
		{
			if (overflow)
				exit (1 && write(2, "Error\n", 6));
			if (!overflow)
			{
				new_node = ft_lstnew(num);
				if(!new_node)
					return (free_lst(a));
				ft_lstadd_back(a, new_node);
				return (1);
			}
		}
	}
	return (0);
}

int		init_a(char **av, t_s **a)
{
	int	i;
	int	j;
	char **current_array;
	
	i = 1;
	if (!av[1])
		return (0);
	while (av[i])
	{
		current_array = ft_split(av[i], ' ');
		j = 0;
		while (current_array[j])
		{
			if	(!try_add(current_array[j], a))
			{	
				free_array(current_array);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
