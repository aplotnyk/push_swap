/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:34:06 by aplotnyk          #+#    #+#             */
/*   Updated: 2023/12/06 15:34:06 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rb(t_stack **stack)
{
	rotate_stack(stack, TRUE);
}

void	rrb(t_stack **stack)
{
	reverse_rotate_stack(stack, TRUE);
}

void	sb(t_stack **stack)
{
	stack_swap(stack, TRUE);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	stack_push_to(stack_a, stack_b);
}
