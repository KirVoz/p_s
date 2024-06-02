/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:34:50 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/02 19:26:36 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_s	*a;
	t_s	*b;
	t_s	*tmp;
	int	max_index;

	if (ac == 1 || (ac == 2 && !av[1][0]))
		exit (1 && write(2, "Error\n", 6));
	max_index = init_a(av, &a);
	make_indexes_for_struct(a);
	max_index = list_length(a) - 1;
	b = NULL;
	if (corner_case(a, max_index))
		return (0);
	tmp = clone_struct(a);
	if (if_close_to_sorted(tmp, max_index, 0, max_index))
	{
		almost_sorted(&a);
		return (0);
	}
	free_lst(&tmp);
	low_num(&a, &b, max_index);
	butterfly_sort(&a, &b);
	back_to_a(&a, &b, max_index);
	return (0);
}
