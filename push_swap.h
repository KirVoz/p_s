#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"



////////initiation////////
int		if_valid(char *str);
int		uniq(int n, t_s *a);
int		try_add(char *current_str, t_s **a);
int		init_a(char **av, t_s **a);
/////////free_handler/////
void	free_array(char **a);
int		free_lst(t_s **a);
////////array_maker//////
int		*make_array(t_s *a);
int		list_length(t_s *a);
void	make_array_great_again(int *arr, t_s *a);
void	make_indexes_for_struct(t_s *a);
////////alkoritms////////
void	rb_ra(t_s **b, int how_many_times, int num);
void	rotate(t_s **stack, int how_many_times);
void	push(t_s **from, t_s **to);
void	pb(t_s **a, t_s **b);
void	pa(t_s **a, t_s **b);
void	rrb_rra(t_s **b, int how_many_times, int num);
///////butterfly/////////
void	butterfly_sort(t_s **a, t_s **b);
int		magic(int n);
void	back_to_a(t_s **a, t_s **b, int max_index);
void	rotate_up_or_down(t_s **b, int max_index);
//////corner_case////////
int		corner_case(t_s *a, int index);
int		if_close_to_sorted(t_s *a, int max_index, int min_index, int len);
t_s		*clone_struct(t_s *a);
t_s		*find_min(t_s *tmp, int min_index);
//////almost_sorted//////
void	almost_sorted(t_s **a);
/////low_num////////////
void	low_num(t_s **a, t_s **b, int max_index);
void	sort_5(t_s **a, t_s **b, int max_index);
void	sort_3(t_s **a, int overwatch, int max_index);
void	sa(t_s **a);
int		find_two_lowest(t_s **a, int i);
#endif