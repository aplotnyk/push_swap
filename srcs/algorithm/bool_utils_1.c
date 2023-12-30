/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:16:52 by aplotnyk          #+#    #+#             */
/*   Updated: 2023/12/18 14:16:52 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	in_first_second(t_stack *node, t_stack *stack_a, t_stack *stack_b,
		int index_in_b)
{
	return (in_first_half_a(node, stack_a) && !in_first_half_b(stack_b,
			index_in_b));
}

int	in_second_first(t_stack *node, t_stack *stack_a, t_stack *stack_b,
			int index_in_b)
{
	return (!in_first_half_a(node, stack_a) && in_first_half_b(stack_b,
			index_in_b));
}

int	in_first_half_both(t_stack *node, t_stack *stack_a, t_stack *stack_b,
		int index_in_b)
{
	return (in_first_half_a(node, stack_a) && in_first_half_b(stack_b,
			index_in_b));
}

int	in_second_half_both(t_stack *node, t_stack *stack_a, t_stack *stack_b,
		int index_in_b)
{
	return (!in_first_half_a(node, stack_a) && !in_first_half_b(stack_b,
			index_in_b));
}

int	can_rotate_both(t_stack *node, t_stack *stack_a, t_stack *stack_b,
		int index_in_b)
{
	return (in_first_half_both(node, stack_a, stack_b, index_in_b)
		|| in_second_half_both(node, stack_a, stack_b, index_in_b));
}
