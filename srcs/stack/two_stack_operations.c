/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stack_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:27:16 by aplotnyk          #+#    #+#             */
/*   Updated: 2023/12/18 18:27:16 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 * simultaneous swap of both stacks
*/
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	stack_swap(stack_a, FALSE);
	stack_swap(stack_b, FALSE);
	write(1, "ss\n", 3);
}

/*
 * simultaneous rotation of both stacks
*/
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_stack(stack_a, FALSE);
	rotate_stack(stack_b, FALSE);
	write(1, "rr\n", 3);
}

/*
 * simultaneous reverse_rotation of both stacks
*/
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_stack(stack_a, FALSE);
	reverse_rotate_stack(stack_b, FALSE);
	write(1, "rrr\n", 4);
}
