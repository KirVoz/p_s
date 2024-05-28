/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:34:50 by kvoznese          #+#    #+#             */
/*   Updated: 2024/05/28 19:32:07 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_s 	*a;
	t_s		*b;
	t_s		*tmp;
	int		max_index;

	if (ac == 1 || (ac == 2 && !av[1][0]))
		exit (1 && write(2, "Error\n", 6));
	int success = init_a(av, &a);
	make_indexes_for_struct(a);
	max_index = list_length(a) - 1;
	b = NULL;
	if (corner_case(a, max_index))
		return (0);
	tmp = clone_struct(a);
	if (if_close_to_sorted(tmp, max_index, 0, max_index))
	{
		return (0);
		// функция которая ищет минимальное количество сдвигов
	}
	free_lst(&tmp);
	butterfly_sort(&a, &b);
	
	// if (success)
	// {
	// 	t_s *test = b;
	// 	while(test)
	// 	{
	// 		//printf("B _ %d\n", test->index);
	// 		test = test->next;
	// 	}
	// }
	
	back_to_a(&a, &b, max_index);
	
	//(void)success;
	if (success)
	{
		t_s *test = a;
		while(test)
		{
			printf("A _ %d\n", test->index);
			test = test->next;
		}
	}
	if (success)
	{
		t_s *test = a;
		while(test)
		{
			printf("A-num _ %d\n", test->num);
			test = test->next;
		}
	}
}
