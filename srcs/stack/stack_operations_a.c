/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:29:39 by aplotnyk          #+#    #+#             */
/*   Updated: 2023/12/18 16:29:39 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack **stack)
{
	stack_swap(stack, TRUE);
}

void	ra(t_stack **stack)
{
	rotate_stack(stack, TRUE);
}

void	rra(t_stack **stack)
{
	reverse_rotate_stack(stack, TRUE);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	stack_push_to(stack_b, stack_a);
}
