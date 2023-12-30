/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:32:38 by aplotnyk          #+#    #+#             */
/*   Updated: 2023/12/18 21:32:38 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/***
 * val << || >> from stack_a -> should be placed on bottom of stack_a
 * val > that last && < that 1st from stack_a - should be placed on top
 * iterating to meet 2 val for curr_val to be placed: it's val's future index
 * 
*/
int	find_future_index_in_a(int value, t_stack *stack_a)
{
	int	future_index;

	if (value < find_min_value(stack_a) || value > find_max_value(stack_a))
		return (get_min_elem(stack_a)->index);
	if (value > get_last_elem(stack_a)->data && value < stack_a->data)
		return (0);
	future_index = 1;
	while (stack_a->next != NULL
		&& !(value > stack_a->data && value < stack_a->next->data))
	{
		future_index++;
		stack_a = stack_a->next;
	}
	return (future_index);
}

void	move_b_to_a(t_stack **stack_b, t_stack **stack_a, t_stack *elem)
{
	int	weight_a;
	int	future_index;

	weight_a = 0;
	future_index = find_future_index_in_a(elem->data, *stack_a);
	if (future_index < find_mid_index(*stack_a))
		weight_a += future_index;
	else
		weight_a += ft_lstsize(*stack_a) - future_index;
	if (in_first_half_both(elem, *stack_b, *stack_a, future_index))
		while (weight_a-- != 0)
			ra(stack_a);
	else if (in_first_second(elem, *stack_b, *stack_a, future_index))
		while (weight_a-- != 0)
			reverse_rotate_stack(stack_a, TRUE);
	pa(stack_a, stack_b);
}
