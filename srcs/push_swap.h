/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:53:24 by aplotnyk          #+#    #+#             */
/*   Updated: 2023/12/03 15:53:24 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TRUE 1
# define FALSE 0

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack {
	int				data;
	int				index;
	unsigned int	weight;
	struct s_stack	*next;
	int				is_a;
}					t_stack;

/**************libft************************/
int		ft_atoi(const char *nptr);
long	ft_atoi_long(const char *nptr);
char	**ft_split(char const *s, char c);
int		ft_strlen(const char *str);
int		ft_lstsize(t_stack *list);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);

/**************stack*****************/
void	stack_push_to(t_stack **stack_from, t_stack **stack_to);
void	stack_swap(t_stack **stack, int needs_to_print);
void	rotate_stack(t_stack **stack, int needs_to_print);
void	reverse_rotate_stack(t_stack **stack, int needs_to_print);

/**************subject operations(stack)****************/
void	pb(t_stack **stack_a, t_stack **stack_b);
void	sb(t_stack **stack);
void	sa(t_stack **stack);
void	ra(t_stack **stack);
void	rra(t_stack **stack);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	rb(t_stack **stack);
void	rrb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

/**************pseudo BOOL utilits*******************/
int		can_rotate_both(t_stack *node, t_stack *stack_a,
			t_stack *stack_b, int index_in_b);
int		in_first_half_both(t_stack *node, t_stack *stack_a,
			t_stack *stack_b, int index_in_b);
int		in_second_half_both(t_stack *node, t_stack *stack_a,
			t_stack *stack_b, int index_in_b);
int		in_first_second(t_stack *node, t_stack *stack_a,
			t_stack *stack_b, int index_in_b);
int		in_second_first(t_stack *node, t_stack *stack_a,
			t_stack *stack_b, int index_in_b);
int		in_first_half_a(t_stack *node, t_stack *stack_a);
int		in_first_half_b(t_stack *stack_b, int index_in_b);

/**************move utilits***********************/
void	move_first_second(t_stack **stack_a, t_stack **stack_b,
			int weight_a, int weight_b);
void	move_second_first(t_stack **stack_a, t_stack **stack_b,
			int weight_a, int weight_b);
void	move_second_half(t_stack **stack_a, t_stack **stack_b,
			int weight_a, int weight_b);
void	move_first_half(t_stack **stack_a, t_stack **stack_b,
			int weight_a, int weight_b);

/**************utils for sorting***********************/
int		is_not_sorted(t_stack *stack);
void	assign_weights(t_stack	**stack_a, t_stack **stack_b);
int		find_future_index_in_b(int value, t_stack *stack_b);
int		find_min_value(t_stack *stack);
int		find_max_value(t_stack *stack);
t_stack	*get_min_elem(t_stack *stack);
t_stack	*get_max_elem(t_stack *stack);
t_stack	*find_by_value(t_stack *stack, int value);
t_stack	*get_last_elem(t_stack *stack);
int		find_mid_index(t_stack *stack);
int		calculate_weight(t_stack *elem_a, t_stack *stack_a,
			t_stack *stack_b, int future_index);
void	init_stack(t_stack *stack);
int		find_future_index_in_a(int value, t_stack *stack_a);

/*************moves********************************/
void	move_a_to_b(t_stack **stack_a, t_stack **stack_b,
			t_stack *elem);
void	move_b_to_a(t_stack **stack_b, t_stack **stack_a,
			t_stack *elem);
void	finalize_stack_a(t_stack **stack_a);
void	move_min_to_top(int index, t_stack **stack);

/*************sort******************/
void	sort(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack	**stack_a);

/*************get input**************/
t_stack	*get_input(int argc, char **argv);

/*************Error checks****************/
int		error(int argc, char **argv);
int		digit_check(char *str);
int		duplicate_check(int argc, char **str, int flag);
int		range_check(char *str);

/**************Free memory*******************/
void	ft_free_arr(char **arr);
void	ft_free(t_stack **stack_a, t_stack **stack_b);
void	free_stack(t_stack **stack);

#endif